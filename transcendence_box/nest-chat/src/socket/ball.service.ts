import { Injectable } from "@nestjs/common";


@Injectable()
export class MatchmakingService {
  private ballPos: {x :number, y: number} = {x: 0,y: 0};

  private updatePos(): void {
    //const players = Array.from(this.waitingPlayers);
  }

  public setBallPos(pos: {x:number, y:number}) : void {
    this.ballPos = pos;
  }

  public getBallPos(): {x: number, y: number} {
    return this.ballPos
  }
}
