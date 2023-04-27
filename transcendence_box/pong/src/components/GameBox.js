import React, { useRef } from 'react';
import styled from 'styled-components';
import Ball from './Ball';
import Score from './Score';
import FieldImg from '../img/Field.png';
import Character from './Character.js'
import GameManager from './GameManager';

const PLAYERMODE = 2;
const OPPONENTMODE = 1;
const ONLINEMODE = 0;

const GameBox = (props) => {
    const playerRef = useRef(null);
    const opponentRef = useRef(null);
    const scoreLeft = useRef(null);
    const scoreRight = useRef(null);
    const managerRef = useRef(null);

    return (
        <GameBoxDiv height={props.height} width={props.width}>
            <Score ref={scoreLeft} left={300}></Score>
            <Score ref={scoreRight} left={600}></Score>
            <Character id="Player" ref={playerRef} controlMode={PLAYERMODE} x={100} y={200}/>
            <Character id="Opponent" ref={opponentRef} controlMode={OPPONENTMODE}
             x={props.opponentPosX} y={props.opponentPosY}/>
            <Ball height={props.height} width={props.width} managerRef={managerRef} playerRef={playerRef} opponentRef={opponentRef} scoreLeft={scoreLeft} scoreRight={scoreRight}/>
            <GameManager ref={managerRef} scoreLeft={scoreLeft} scoreRight={scoreRight} height={props.height} width={props.width}></GameManager>
        </GameBoxDiv>
    );
};


const GameBoxDiv = styled.div`
  height: ${(props) => props.height}px;
  width: ${(props) => props.width}px;
  //top : 100px;
  position: relative;
  background-image: url(${FieldImg});
`;

export default GameBox;

