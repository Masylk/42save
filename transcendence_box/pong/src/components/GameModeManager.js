import styled from 'styled-components'
import GameBox from './GameBox';
import MultiplayerManager from './MultiplayerManager';
import FieldImg from '../img/Field.png';
import { useEffect, useState } from 'react';

const LOCAL_OPPONENT_POS_X = 860;
const LOCAL_OPPONENT_POS_Y = 200;

const PLAYERMODE = 2;
const OPPONENTMODE = 1;

const GameModeManager = (props) => {
    const [clicked, setClicked] = useState(false);
    const [mode, setMode] = useState("");
    
    const onClickButton = (button) => {
        setClicked(() =>{return true});
        setMode(button);
    }
    
    useEffect(() =>{
        console.log("Render GameModeManager");

    });

    return (
        <GameModeManagerDiv height={props.height} width={props.width} disabled={clicked}>
            <ButtonLocal onClick={() => onClickButton("Local")} disabled={clicked}>Local</ButtonLocal>
            <ButtonOnline onClick={() => onClickButton("Online")} disabled={clicked}>Online</ButtonOnline>
            {clicked ?
            (mode === "Local" ?
            <GameBox height={props.height} width={props.width} leftPlayer={PLAYERMODE} rightPlayer={OPPONENTMODE}
                opponentPosX={LOCAL_OPPONENT_POS_X} opponentPosY={LOCAL_OPPONENT_POS_Y}></GameBox>
            : <MultiplayerManager height={props.height} width={props.width}></MultiplayerManager>)
            : ""}
        </GameModeManagerDiv>
    )
}

const ButtonLocal = styled.button`
    position: absolute;
    border-radius: 25px;
    top: 200px;
    left: 200px;
    width: 200px;
    height: 200px;
    line-height: 200px;
    text-align: center;
    background-color: white;
    color: red;

    /* apply opacity when button is disabled */
    opacity: ${(props) => (props.disabled ? "0" : "1")};
    pointer-events: ${(props) => (props.disabled ? "none" : "auto")};
`;

const ButtonOnline = styled.button`
    position: absolute;
    border-radius: 25px;
    width: 200px;
    height: 200px;
    line-height: 200px;
    text-align: center;
    background-color: white;
    top: 200px;
    left: 600px;
    color: red;

    opacity: ${(props) => (props.disabled ? "0" : "1")};
    pointer-events: ${(props) => (props.disabled ? "none" : "auto")};
`;

const GameModeManagerDiv = styled.div`
    height: ${(props) => props.height}px;
    width: ${(props) => props.width}px;
    top : 100px;
    position: relative;
    background-image: url(${FieldImg});
`;


export default GameModeManager;