import { Socket } from 'socket.io';
export declare class MatchmakingService {
    private waitingPlayers;
    addPlayer(player: Socket): void;
    removePlayer(player: Socket): void;
    private matchPlayers;
    startMatchmaking(): void;
}
