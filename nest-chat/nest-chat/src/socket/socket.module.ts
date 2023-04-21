import { Module } from "@nestjs/common";
import { SocketEvents } from "./socketEvents";
import { MatchmakingService } from "./matchmaking.service";

@Module({
    providers: [SocketEvents, MatchmakingService]
})
export class SocketModule {}