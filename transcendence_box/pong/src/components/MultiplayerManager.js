import { useEffect, useState } from 'react';
import GameBox from './GameBox';
import io from 'socket.io-client'
import WaitingBox from './WaitingBox'

const STARTPOS_Y = 200;
const STARTPOS_X = 860;
const ONLINEMODE = 0;

const MultiplayerManager = (props) => {
    const [infos, setInfos] = useState({
        opponentX: STARTPOS_X,
        opponentY: STARTPOS_Y,
        userId: Math.floor(Math.random() * 9999) + 1,
        matchFound: false,
    })

    // const socket = io('ws://localhost:8000');

    useEffect(() => {
        const socket=io.connect("http://localhost:8000", {
            query: {
                userId: infos.userId
            }
        })
        
        window.addEventListener('beforeunload', () => {
            socket.disconnect();
          });

        
        // Listen to the 'connect' event
        socket.on('connect', () => {
            console.log('Connected to socket.io server');
            console.log('User Id :' + infos.userId);
        });
        
        socket.on('game-start', () => {
            console.log("match found !");
            setInfos(prevInfos => ({
                ...prevInfos,
                matchFound: true
              }));
        })
        socket.on('connect_error', (error) => {
            console.error('Failed to connect to socket.io server', error);
        });
        
        // Listen to the 'opponentMoved' event
        socket.on('opponentMoved', (data) => {
           setInfos({
              opponentX: data.x,
              opponentY: data.y,
           });
        });
        
        // Emit a 'playerMoved' event
        // const handleMove = (x, y) => {
        //    socket.emit('playerMoved', { x, y });
        // }
        
        // Clean up the event listeners when the component unmounts
        return () => {
            window.removeEventListener('beforeunload', () => {
                socket.disconnect();
              });
           socket.off('connect');
           socket.off('opponentMoved');
           socket.disconnect();
        };
     }, [infos]);

    return (
        infos.matchFound === true ? (
          <GameBox height={props.height} width={props.width}
            opponentPosX={infos.opponentX} opponentPosY={infos.opponentY} controlMode={ONLINEMODE}
          />
        ) : (
          <WaitingBox height={props.height} width={props.width} />
        )
      );
}


 
export default MultiplayerManager;