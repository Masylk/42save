"use strict";
var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.MatchmakingService = void 0;
const common_1 = require("@nestjs/common");
const ball_service_1 = require("./ball.service");
const ONLINEMODE = 0;
const PLAYERMODE = 2;
let MatchmakingService = class MatchmakingService {
    constructor() {
        this.waitingPlayers = new Set();
        this.ballServices = new Set();
    }
    addPlayer(player) {
        this.waitingPlayers.add(player);
    }
    removePlayer(player) {
        this.waitingPlayers.delete(player);
    }
    getRoomSockets(room, server) {
        const roomSockets = Array.from(server.sockets.adapter.rooms.get(room) || new Set());
        const sockets = roomSockets.map(socketId => server.sockets.sockets.get(String(socketId)));
        return sockets;
    }
    deleteBallService(socket) {
        for (const ballService of this.ballServices) {
            if (ballService.containSocket(socket)) {
                this.ballServices.delete(ballService);
                return;
            }
        }
    }
    matchPlayers(server) {
        if (this.waitingPlayers.size >= 2) {
            const [player1, player2] = [...this.waitingPlayers.values()].slice(0, 2);
            const playerOne = {
                socket: player1,
                pos: { x: 100, y: 200 },
                rect: { x: 100, y: 200, width: 10, height: 10 }
            };
            const playerTwo = {
                socket: player2,
                pos: { x: 860, y: 200 },
                rect: { x: 860, y: 200, width: 10, height: 10 }
            };
            this.waitingPlayers.delete(player1);
            this.waitingPlayers.delete(player2);
            console.log("Match found !");
            const room = `${player1.id}-${player2.id}`;
            player1.join(room);
            player2.join(room);
            player1.emit('game-start', PLAYERMODE, ONLINEMODE);
            player2.emit('game-start', ONLINEMODE, PLAYERMODE);
            const newBallService = new ball_service_1.BallService();
            this.ballServices.add(newBallService);
            newBallService.setBallLoop(server, playerOne, playerTwo, room, 10);
        }
    }
    startMatchmaking(server) {
        setInterval(() => {
            this.matchPlayers(server);
        }, 5000);
    }
};
MatchmakingService = __decorate([
    (0, common_1.Injectable)()
], MatchmakingService);
exports.MatchmakingService = MatchmakingService;
//# sourceMappingURL=matchmaking.service.js.map