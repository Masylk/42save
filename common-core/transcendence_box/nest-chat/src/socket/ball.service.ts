import { Injectable } from "@nestjs/common";
import { ConnectedSocket, MessageBody, SubscribeMessage, WebSocketGateway, WebSocketServer } from "@nestjs/websockets";
import { Server, Socket } from 'socket.io';

const GAME_WIDTH = 991;
const GAME_HEIGHT = 678;
const BALL_RADIUS = 10;
const BALL_SIZE = BALL_RADIUS * 2;
const BASE_VELOCITY = 2;
const HEIGHT_OFFSET = 30;
const CHARACTER_WIDTH = 30;
const CHARACTER_HEIGHT = 250;
const MAX_VELOCITY = 6;
const BOUNCE_ACCELERATION = 1.1;

@Injectable()
export class BallService {
  private ballPos: {x :number, y: number} = {x: GAME_WIDTH / 2, y: GAME_HEIGHT / 2};
  private velocity: {x: number, y: number} = {x: BASE_VELOCITY, y: BASE_VELOCITY};
  private leftPlayer: {x :number, y: number, width: number, height: number} = {x: 100,y: 200, width: CHARACTER_WIDTH, height: CHARACTER_HEIGHT};
  private rightPlayer: {x :number, y: number, width: number, height: number} = {x: 860,y: 200, width: CHARACTER_WIDTH, height: CHARACTER_HEIGHT};
  private interval = null;
  private isColliding: boolean = false;
  private scoreLeft = 0;
  private scoreRight = 0;
  private pOneSocket;
  private pTwoSocket;

  public setBallLoop(server, playerOne, playerTwo, room, ms) {

// Countdown avant le début de la partie
    let timer = 3;
    
    this.pOneSocket = playerOne.socket;
    this.pTwoSocket = playerTwo.socket;

    playerOne.socket.on('player-moved', (data) => {
      this.leftPlayer.x = data.pos.x;
      this.leftPlayer.y = data.pos.y;
      playerTwo.socket.emit("opponent-moved", this.leftPlayer)
    })
    playerTwo.socket.on('player-moved', (data) => {
      this.rightPlayer.x = data.pos.x;
      this.rightPlayer.y = data.pos.y;
      playerOne.socket.emit("opponent-moved", this.rightPlayer)
    })
    const readyIntervale = setInterval(() => {
        timer--;
        playerOne.socket.to(room).emit("ready-timer", timer);
        playerTwo.socket.to(room).emit("ready-timer", timer);
      }, 1000);
  
    if (this.interval === null)
    {
      setTimeout(() => {
// Clear the interval after emitting the delayed event
        clearInterval(readyIntervale);
        timer--;
        playerOne.socket.to(room).emit("ready-timer", timer);
        playerTwo.socket.to(room).emit("ready-timer", timer);
       

// Boucle pour update la position de la balle
        this.interval = setInterval(() => {
          this.updatePos(server, room);
// Emit la position de la balle aux clients
          server.to(room).emit("ball-moved", this.ballPos);
          if (this.scoreLeft >= 10 || this.scoreRight >= 10)
          {
            this.unsetBallLoop();
          }
        }, ms);
      }, 3000);
    }

  }

  //désactiver la boucle lorsque la partie est terminée
  public unsetBallLoop() {
    clearInterval(this.interval)
  }

  public containSocket(socket: Socket) {
    return (socket === this.pOneSocket || socket === this.pTwoSocket)  
  }

  private checkCollision = (ballRect, characterRect) => {
        
    if (ballRect.x + BALL_RADIUS > characterRect.x &&
      ballRect.x - BALL_RADIUS < characterRect.x + characterRect.width &&
      ballRect.y + BALL_RADIUS > characterRect.y &&
      ballRect.y - BALL_RADIUS < characterRect.y + characterRect.height)
      return (true)
    return (false)
  }

  //update la position de la balle en fonction de sa trajectoire
  private updatePos(server, room): void {
    //déplacement selon sa trajectoire
    this.ballPos.x += this.velocity.x;
    this.ballPos.y += this.velocity.y;
    //Collision avec le but (envoyer l'event goal-scored-j1 ou j2)
    if (this.ballPos.x <= 0 + 10 || this.ballPos.x + BALL_SIZE >= GAME_WIDTH - 10) {
      if (this.ballPos.x <= 0 + 10)
      {
        server.to(room).emit('goal-scored-j2');
        this.scoreRight++;
      }
      if (this.ballPos.x + BALL_SIZE >= GAME_WIDTH - 10)
      {
        server.to(room).emit('goal-scored-j1');
        this.scoreLeft++;
      }
      this.ballPos.x = GAME_WIDTH / 2;
      this.ballPos.y = GAME_HEIGHT / 2;
    }
    
    //Collision avec le mur
    if (this.ballPos.y <= 0 + HEIGHT_OFFSET || this.ballPos.y + BALL_SIZE >= GAME_HEIGHT - HEIGHT_OFFSET) {
      if (!this.isColliding)
      {
        this.velocity.y = -this.velocity.y;
        this.isColliding = true;
      }
    }
    //Collision avec le joueur
    else if ((this.checkCollision(this.ballPos, this.leftPlayer)) ||
        (this.checkCollision(this.ballPos, this.rightPlayer)))
    {
      if (!this.isColliding)
      {
        this.velocity.x = -this.velocity.x
        this.isColliding = true;
      }
    }
    else 
      this.isColliding = false;

    }
  
  public setBallPos(pos: {x:number, y:number}) : void {
    this.ballPos = pos;
  }

  public getBallPos(): {x: number, y: number} {
    return this.ballPos
  }

  //when game end clear th
}
