import { Socket } from 'socket.io';
import { Injectable } from "@nestjs/common";

const ONLINEMODE = 0;
const PLAYERMODE = 2;

@Injectable()
export class MatchmakingService {
  private waitingPlayers = new Set<Socket>();

  public addPlayer(player: Socket): void {
    this.waitingPlayers.add(player);
  }

  public removePlayer(player: Socket): void {
        //Do something
        this.waitingPlayers.delete(player)
    }

  private matchPlayers(): void {
    //const players = Array.from(this.waitingPlayers);

    if (this.waitingPlayers.size >= 2) {
        const [player1, player2] = 
        [...this.waitingPlayers.values()].slice(0, 2);

        this.waitingPlayers.delete(player1);
        this.waitingPlayers.delete(player2);

        console.log("Match found !")
        // create a new room for the players to play
        const room = `${player1.id}-${player2.id}`;
        player1.join(room);
        player2.join(room);
        // notify the players that the game has started
        player1.to(room).emit('game-start', PLAYERMODE, ONLINEMODE);
        player2.to(room).emit('game-start', ONLINEMODE, PLAYERMODE);
    }
  }

  public startMatchmaking(): void {
    setInterval(() => {
      this.matchPlayers();
    }, 5000);
  }
}
