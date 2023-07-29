import { Server, Socket } from 'socket.io';
import { Injectable } from "@nestjs/common";
import { BallService } from './ball.service';

const ONLINEMODE = 0;
const PLAYERMODE = 2;

@Injectable()
export class MatchmakingService {
  private waitingPlayers = new Set<Socket>();
  private ballServices = new Set<BallService>();


  public addPlayer(player: Socket): void {
    this.waitingPlayers.add(player);
  }

  public removePlayer(player: Socket): void {
        //Do something
        this.waitingPlayers.delete(player)
    }

  getRoomSockets(room: string, server: Server): Socket[] {
    const roomSockets = Array.from(server.sockets.adapter.rooms.get(room) || new Set());

    // Get socket objects from their IDs
    const sockets = roomSockets.map(socketId => server.sockets.sockets.get(String(socketId)));

    return sockets;
  }

  public deleteBallService(socket: Socket)
  {
    for (const ballService of this.ballServices) {
      if (ballService.containSocket(socket))
      {
        this.ballServices.delete(ballService)
        return ;
      }
    }
  }

  private matchPlayers(server: Server): void {
    //const players = Array.from(this.waitingPlayers);

    if (this.waitingPlayers.size >= 2) {
        const [player1, player2] = 
        [...this.waitingPlayers.values()].slice(0, 2);

        const playerOne = {
          socket: player1,
          pos: {x: 100, y: 200},
          rect: {x: 100, y: 200, width: 10, height: 10}
        }

        const playerTwo = {
          socket: player2,
          pos: {x: 860, y: 200},
          rect: {x: 860, y: 200, width: 10, height: 10}
        }
        this.waitingPlayers.delete(player1);
        this.waitingPlayers.delete(player2);

        console.log("Match found !")
        // create a new room for the players to play
        const room = `${player1.id}-${player2.id}`;
        player1.join(room);
        player2.join(room);
        // notify the players that the game has started
        player1.emit('game-start', PLAYERMODE, ONLINEMODE);
        player2.emit('game-start', ONLINEMODE, PLAYERMODE);

        const newBallService = new BallService();

        this.ballServices.add(newBallService);
        newBallService.setBallLoop(server, playerOne, playerTwo, room, 10)
    }
  }

  public startMatchmaking(server): void {
    setInterval(() => {
      this.matchPlayers(server);
    }, 5000);
  }
}
