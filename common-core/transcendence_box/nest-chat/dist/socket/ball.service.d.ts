import { Socket } from 'socket.io';
export declare class BallService {
    private ballPos;
    private velocity;
    private leftPlayer;
    private rightPlayer;
    private interval;
    private isColliding;
    private scoreLeft;
    private scoreRight;
    private pOneSocket;
    private pTwoSocket;
    setBallLoop(server: any, playerOne: any, playerTwo: any, room: any, ms: any): void;
    unsetBallLoop(): void;
    containSocket(socket: Socket): boolean;
    private checkCollision;
    private updatePos;
    setBallPos(pos: {
        x: number;
        y: number;
    }): void;
    getBallPos(): {
        x: number;
        y: number;
    };
}
