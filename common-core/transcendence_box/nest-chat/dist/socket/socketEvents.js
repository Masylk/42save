"use strict";
var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (this && this.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};
var __param = (this && this.__param) || function (paramIndex, decorator) {
    return function (target, key) { decorator(target, key, paramIndex); }
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.SocketEvents = void 0;
const websockets_1 = require("@nestjs/websockets");
const socket_io_1 = require("socket.io");
const matchmaking_service_1 = require("./matchmaking.service");
const common_1 = require("@nestjs/common");
let SocketEvents = class SocketEvents {
    constructor(matchmakingService) {
        this.matchmakingService = matchmakingService;
        this.waitingPlayers = new Map();
    }
    afterInit(server) {
        this.matchmakingService.startMatchmaking(this.server);
    }
    handleConnection(client) {
        console.log(`Client Connected: ${client.id}`);
        let userId = Array.isArray(client.handshake.query.userId)
            ? client.handshake.query.userId[0]
            : client.handshake.query.userId.toString();
        console.log(`Client Connected: ${client.handshake.query.userId}`);
        this.waitingPlayers.set(userId, client);
        this.matchmakingService.addPlayer(client);
        client.emit('searching');
    }
    handleDisconnect(client) {
        console.log(`Client Disconnected: ${client.id}`);
        this.matchmakingService.removePlayer(client);
        this.matchmakingService.deleteBallService(client);
    }
    handleMatchmaking(data, client) {
    }
    handleMessage(data, client) {
        console.log("message received : " + data);
        this.server.emit('chat', client.id, data);
    }
};
__decorate([
    (0, websockets_1.WebSocketServer)(),
    __metadata("design:type", socket_io_1.Server)
], SocketEvents.prototype, "server", void 0);
__decorate([
    (0, websockets_1.SubscribeMessage)('multiplayer'),
    __param(0, (0, websockets_1.MessageBody)()),
    __param(1, (0, websockets_1.ConnectedSocket)()),
    __metadata("design:type", Function),
    __metadata("design:paramtypes", [String, socket_io_1.Socket]),
    __metadata("design:returntype", void 0)
], SocketEvents.prototype, "handleMatchmaking", null);
__decorate([
    (0, websockets_1.SubscribeMessage)('message'),
    __param(0, (0, websockets_1.MessageBody)()),
    __param(1, (0, websockets_1.ConnectedSocket)()),
    __metadata("design:type", Function),
    __metadata("design:paramtypes", [String, socket_io_1.Socket]),
    __metadata("design:returntype", void 0)
], SocketEvents.prototype, "handleMessage", null);
SocketEvents = __decorate([
    (0, common_1.Injectable)(),
    (0, websockets_1.WebSocketGateway)({
        cors: {
            origin: '*',
        },
    }),
    __metadata("design:paramtypes", [matchmaking_service_1.MatchmakingService])
], SocketEvents);
exports.SocketEvents = SocketEvents;
//# sourceMappingURL=socketEvents.js.map