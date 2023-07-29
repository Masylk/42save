import { Server, Socket } from 'socket.io';
export declare class MatchmakingService {
    private waitingPlayers;
    private ballServices;
    addPlayer(player: Socket): void;
    removePlayer(player: Socket): void;
    getRoomSockets(room: string, server: Server): Socket[];
    deleteBallService(socket: Socket): void;
    private matchPlayers;
    startMatchmaking(server: any): void;
}
