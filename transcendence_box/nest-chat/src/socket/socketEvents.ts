import { ConnectedSocket, MessageBody, SubscribeMessage, WebSocketGateway, WebSocketServer } from "@nestjs/websockets";
import { Server, Socket } from 'socket.io';
import { OnGatewayInit, OnGatewayConnection, OnGatewayDisconnect } from "@nestjs/websockets";
import { MatchmakingService } from './matchmaking.service'
import { Injectable } from "@nestjs/common";

@Injectable()
@WebSocketGateway({
    cors: {
        origin: '*',
    },
})
export class SocketEvents  implements OnGatewayInit, OnGatewayConnection, OnGatewayDisconnect{
    @WebSocketServer()
    server: Server;
    waitingPlayers: Map<string, Socket> = new Map();
    
    constructor (private matchmakingService: MatchmakingService){}

    afterInit(server: any) {
        this.matchmakingService.startMatchmaking();
    }
    //connexion
    handleConnection(client: Socket){
       console.log(`Client Connected: ${client.id}`);
        let userId = Array.isArray(client.handshake.query.userId)
                    ? client.handshake.query.userId[0]
                    : client.handshake.query.userId.toString();
        console.log(`Client Connected: ${client.handshake.query.userId}`);
        this.waitingPlayers.set(userId, client)
        this.matchmakingService.addPlayer(client)
        client.emit('searching');
    }

    

    handleDisconnect(client: Socket){
        console.log(`Client Disconnected: ${client.id}`);
        this.matchmakingService.removePlayer(client)
    }

    //multiplayer event
    @SubscribeMessage('multiplayer')
    handleMatchmaking(@MessageBody() data: string, @ConnectedSocket() client: Socket){

    }

    //message event
    @SubscribeMessage('message')
    handleMessage(@MessageBody() data: string, @ConnectedSocket() client: Socket){
        console.log("message received : " + data)
        this.server.emit('chat', client.id, data);
    }

}