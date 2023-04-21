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
let MatchmakingService = class MatchmakingService {
    constructor() {
        this.waitingPlayers = new Set();
    }
    addPlayer(player) {
        this.waitingPlayers.add(player);
    }
    removePlayer(player) {
    }
    matchPlayers() {
        if (this.waitingPlayers.size >= 2) {
            const [player1, player2] = [...this.waitingPlayers.values()].slice(0, 2);
            this.waitingPlayers.delete(player1);
            this.waitingPlayers.delete(player2);
            console.log("Match found !");
            const room = `${player1.id}-${player2.id}`;
            player1.join(room);
            player2.join(room);
            player1.to(room).emit('game-start', room);
            player2.to(room).emit('game-start', room);
        }
    }
    startMatchmaking() {
        setInterval(() => {
            this.matchPlayers();
        }, 5000);
    }
};
MatchmakingService = __decorate([
    (0, common_1.Injectable)()
], MatchmakingService);
exports.MatchmakingService = MatchmakingService;
//# sourceMappingURL=matchmaking.service.js.map