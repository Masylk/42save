import { Injectable } from '@nestjs/common';
import * as Pusher from "pusher"

@Injectable()
export class PusherService {
    pusher: Pusher;

    constructor() {
        this.pusher = new Pusher({
            appId: "1586147",
            key: "31ea48981079b0b4e216",
            secret: "85396598c12a85680237",
            cluster: "eu",
            useTLS: true
          });
    }

    async trigger(channel: string, event: string, data:any){
        await this.pusher.trigger(channel, event, data);
    }
}
