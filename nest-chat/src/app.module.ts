import { Module } from '@nestjs/common';
import { AppController } from './app.controller';
import { PusherService } from './pusher.service';
import { SocketModule } from './socket/socket.module'

@Module({
  imports: [SocketModule],
  controllers: [AppController],
  providers: [PusherService],
})
export class AppModule {}
