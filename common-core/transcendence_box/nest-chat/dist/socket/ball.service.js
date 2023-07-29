"use strict";
var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.BallService = void 0;
const common_1 = require("@nestjs/common");
const GAME_WIDTH = 991;
const GAME_HEIGHT = 678;
const BALL_RADIUS = 10;
const BALL_SIZE = BALL_RADIUS * 2;
const BASE_VELOCITY = 2;
const HEIGHT_OFFSET = 30;
const CHARACTER_WIDTH = 30;
const CHARACTER_HEIGHT = 250;
const MAX_VELOCITY = 6;
const BOUNCE_ACCELERATION = 1.1;
let BallService = class BallService {
    constructor() {
        this.ballPos = { x: GAME_WIDTH / 2, y: GAME_HEIGHT / 2 };
        this.velocity = { x: BASE_VELOCITY, y: BASE_VELOCITY };
        this.leftPlayer = { x: 100, y: 200, width: CHARACTER_WIDTH, height: CHARACTER_HEIGHT };
        this.rightPlayer = { x: 860, y: 200, width: CHARACTER_WIDTH, height: CHARACTER_HEIGHT };
        this.interval = null;
        this.isColliding = false;
        this.scoreLeft = 0;
        this.scoreRight = 0;
        this.checkCollision = (ballRect, characterRect) => {
            if (ballRect.x + BALL_RADIUS > characterRect.x &&
                ballRect.x - BALL_RADIUS < characterRect.x + characterRect.width &&
                ballRect.y + BALL_RADIUS > characterRect.y &&
                ballRect.y - BALL_RADIUS < characterRect.y + characterRect.height)
                return (true);
            return (false);
        };
    }
    setBallLoop(server, playerOne, playerTwo, room, ms) {
        let timer = 3;
        this.pOneSocket = playerOne.socket;
        this.pTwoSocket = playerTwo.socket;
        playerOne.socket.on('player-moved', (data) => {
            this.leftPlayer.x = data.pos.x;
            this.leftPlayer.y = data.pos.y;
            playerTwo.socket.emit("opponent-moved", this.leftPlayer);
        });
        playerTwo.socket.on('player-moved', (data) => {
            this.rightPlayer.x = data.pos.x;
            this.rightPlayer.y = data.pos.y;
            playerOne.socket.emit("opponent-moved", this.rightPlayer);
        });
        const readyIntervale = setInterval(() => {
            timer--;
            playerOne.socket.to(room).emit("ready-timer", timer);
            playerTwo.socket.to(room).emit("ready-timer", timer);
        }, 1000);
        if (this.interval === null) {
            setTimeout(() => {
                clearInterval(readyIntervale);
                timer--;
                playerOne.socket.to(room).emit("ready-timer", timer);
                playerTwo.socket.to(room).emit("ready-timer", timer);
                this.interval = setInterval(() => {
                    this.updatePos(server, room);
                    server.to(room).emit("ball-moved", this.ballPos);
                    if (this.scoreLeft >= 10 || this.scoreRight >= 10) {
                        this.unsetBallLoop();
                    }
                }, ms);
            }, 3000);
        }
    }
    unsetBallLoop() {
        clearInterval(this.interval);
    }
    containSocket(socket) {
        return (socket === this.pOneSocket || socket === this.pTwoSocket);
    }
    updatePos(server, room) {
        this.ballPos.x += this.velocity.x;
        this.ballPos.y += this.velocity.y;
        if (this.ballPos.x <= 0 + 10 || this.ballPos.x + BALL_SIZE >= GAME_WIDTH - 10) {
            if (this.ballPos.x <= 0 + 10) {
                server.to(room).emit('goal-scored-j2');
                this.scoreRight++;
            }
            if (this.ballPos.x + BALL_SIZE >= GAME_WIDTH - 10) {
                server.to(room).emit('goal-scored-j1');
                this.scoreLeft++;
            }
            this.ballPos.x = GAME_WIDTH / 2;
            this.ballPos.y = GAME_HEIGHT / 2;
        }
        if (this.ballPos.y <= 0 + HEIGHT_OFFSET || this.ballPos.y + BALL_SIZE >= GAME_HEIGHT - HEIGHT_OFFSET) {
            if (!this.isColliding) {
                this.velocity.y = -this.velocity.y;
                this.isColliding = true;
            }
        }
        else if ((this.checkCollision(this.ballPos, this.leftPlayer)) ||
            (this.checkCollision(this.ballPos, this.rightPlayer))) {
            if (!this.isColliding) {
                this.velocity.x = -this.velocity.x;
                this.isColliding = true;
            }
        }
        else
            this.isColliding = false;
    }
    setBallPos(pos) {
        this.ballPos = pos;
    }
    getBallPos() {
        return this.ballPos;
    }
};
BallService = __decorate([
    (0, common_1.Injectable)()
], BallService);
exports.BallService = BallService;
//# sourceMappingURL=ball.service.js.map