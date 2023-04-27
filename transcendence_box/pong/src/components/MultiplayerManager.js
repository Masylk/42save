import { useState } from 'react';
import GameBox from './GameBox';
import styled from 'styled-components'

const MultiplayerManager = (props) => {
    const [infos, setInfos] = useState({
        opponentX: 860,
        opponentY: 200,
    })
    return (
        <GameBox height={props.height} width={props.width}
        opponentPosX={infos.opponentX} opponentPosY={infos.opponentY}></GameBox>
    )
}

export default MultiplayerManager;