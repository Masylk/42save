import { Injectable } from "@nestjs/common";


@Injectable()
export class MatchmakingService {
  private ballPos: {x :number, y: number} = {x: 0,y: 0};
  private leftPlayer: {x :number, y: number} = {x: 0,y: 0};
  private rightPlayer: {x :number, y: number} = {x: 0,y: 0};
  private inteval = null;

  //lancer la boucle lorsque la partie commence
  public setBallLoop(ms: number, playerone, playertwo) {
  //Boucle pour update la position de la balle
    if (this.inteval === null)
    {
      this.leftPlayer = playerone;
      this.rightPlayer = playertwo;
      this.inteval = setInterval(() => {
        this.updatePos();
        console.log('This will be executed at a fixed interval');
      }, ms);
    }
  }

  //désactiver la boucle lorsque la partie est terminée
  public unsetBallLoop() {
    clearInterval(this.inteval)
    this.inteval = null;
    this.leftPlayer = null;
    this.rightPlayer = null;
  }

  //update la position de la balle en fonction de sa trajectoire
  private updatePos(): void {
    //déplacement selon sa trajectoire

    //Collision avec le mur

    //Collision avec le joueur

    //Collision avec le but (envoyer l'event goal-scored-j1 ou j2)

    //renvoyer la position de la balle au client
   
    //const players = Array.from(this.waitingPlayers);
  }

  public setBallPos(pos: {x:number, y:number}) : void {
    this.ballPos = pos;
  }

  public getBallPos(): {x: number, y: number} {
    return this.ballPos
  }

  //when game end clear th
}
