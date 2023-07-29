
import React, { useEffect, useState } from 'react';
import styled from 'styled-components';
import birdImg from '../img/Player 1.png';

const ACCELERATION = 10;
const MAX_SPEED = ACCELERATION * 2;
const BIRD_WIDTH = 31;
const BIRD_HEIGHT = 218;
const ONLINEMODE = 0;
const PLAYERMODE = 1;
const OPPONENTMODE = 2;

const Character = React.forwardRef((props, ref) => {
    const [characterPosition, setCharacterPosition] = useState({ x: props.x, y: props.y });
    const [characterSpeed, setCharacterSpeed] = useState({ x: 0, y: 0 });
    let [isKeyDown, setIsKeyDown] = useState(false);
    
    useEffect(() => {
      const handleKeyDown = (event) => {
        setIsKeyDown(true);
        switch (event.key.toLowerCase()) {
          case props.controlMode === PLAYERMODE ? 'arrowup' : 'w':
            setCharacterSpeed((prevSpeed) => ({
              x: prevSpeed.x,
              y: Math.max(prevSpeed.y - ACCELERATION, -MAX_SPEED),
            }));
            break;
          case props.controlMode === PLAYERMODE ? 'arrowup' : 'z':
            setCharacterSpeed((prevSpeed) => ({
              x: prevSpeed.x,
              y: Math.max(prevSpeed.y - ACCELERATION, -MAX_SPEED),
            }));
            break;
          case props.controlMode === PLAYERMODE ? 'arrowdown' : 's':
            setCharacterSpeed((prevSpeed) => ({
              x: prevSpeed.x,
              y: Math.min(prevSpeed.y + ACCELERATION, MAX_SPEED),
            }));
            break;
          default:
            break;
        }
      };
  
      const handleKeyUp = (event) => {
        switch (event.key.toLowerCase()) {
          case props.controlMode === PLAYERMODE ? 'arrowup' : 'w':
            setCharacterSpeed({ x: 0, y: 0 });
            setIsKeyDown(false);
            break;
          case props.controlMode === PLAYERMODE ? 'arrowup' : 'z':
            setCharacterSpeed({ x: 0, y: 0 });
            setIsKeyDown(false);
            break;
          case props.controlMode === PLAYERMODE ? 'arrowdown' : 's':
            setCharacterSpeed({ x: 0, y: 0 });
            setIsKeyDown(false);
            break;
          default:
            break;
        }
      };
      if (props.controlMode === PLAYERMODE || props.controlMode === OPPONENTMODE)
      {
        window.addEventListener('keydown', handleKeyDown);
        window.addEventListener('keyup', handleKeyUp);
    
        return () => {
          window.removeEventListener('keydown', handleKeyDown);
          window.removeEventListener('keyup', handleKeyUp);
        };
      }
    }, [characterPosition, props.controlMode]);
  
    useEffect(() => {
      if (isKeyDown) {
          const intervalId = setInterval(() => {
            setCharacterPosition((prevPosition) => ({
              x: prevPosition.x + characterSpeed.x,
              y: Math.min(Math.max(prevPosition.y + characterSpeed.y, 30), 430)
            }));
            if (props.socket !== null && props.controlMode === OPPONENTMODE)
            {
              props.socket.emit("player-moved", {
                userId: props.userId,
                pos: characterPosition,
              })
            }
          }, 16);
          return () => {
            clearInterval(intervalId);
          };
      }
    }, [characterSpeed, isKeyDown, props.socket, characterPosition, props.userId, props.controlMode]);
    
    useEffect(() => {
      if (props.controlMode === ONLINEMODE)
      {
        if (props.socket !== null)
        {
          props.socket.on('opponent-moved', (pos) => {
            setCharacterPosition({
              x: pos.x,
              y: pos.y,
            })

          })
        }
      }
    }, [props.controlMode, props.socket])

    return (
      <CharacterDiv ref={ref} height={BIRD_HEIGHT} width={BIRD_WIDTH} x={characterPosition.x} y={characterPosition.y} />
    );
  });
  

  const CharacterDiv = styled.div.attrs((props) => ({
    style: {
      position: 'absolute',
      backgroundImage: `url(${birdImg})`,
      backgroundColor: 'red',
      height: `${props.height}px`,
      width: `${props.width}px`,
      left: `${props.x}px`,
      top: `${props.y}px`,
      borderRadius: '0%',
    },
  }))``;

export default Character;