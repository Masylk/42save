import { Server, Socket } from 'socket.io';
import { OnGatewayInit, OnGatewayConnection, OnGatewayDisconnect } from "@nestjs/websockets";
import { MatchmakingService } from './matchmaking.service';
export declare class SocketEvents implements OnGatewayInit, OnGatewayConnection, OnGatewayDisconnect {
    private matchmakingService;
    server: Server;
    waitingPlayers: Map<string, Socket>;
    constructor(matchmakingService: MatchmakingService);
    afterInit(server: any): void;
    handleConnection(client: Socket): void;
    handleDisconnect(client: Socket): void;
    handleMatchmaking(data: string, client: Socket): void;
    handleMessage(data: string, client: Socket): void;
}
