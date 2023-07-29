import { Module } from "@nestjs/common";
import { SocketEvents } from "./socketEvents";
import { MatchmakingService } from "./matchmaking.service";
import { BallService } from "./ball.service";

@Module({
    providers: [SocketEvents, MatchmakingService, BallService]
})
export class SocketModule {}