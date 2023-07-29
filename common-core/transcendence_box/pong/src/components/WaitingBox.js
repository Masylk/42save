import React, { useRef } from 'react';
import styled from 'styled-components';
import FieldImg from '../img/Field.png';

const WaitingBox = (props) => {

    return (
        <WaitingBoxDiv height={props.height} width={props.width}>Waiting...</WaitingBoxDiv>
    )
}

const WaitingBoxDiv = styled.div`
    height: ${(props) => props.height}px;
    width: ${(props) => props.width}px;
    //top : 100px;
    text-shadow: 2px 0 #fff, -2px 0 #fff, 0 2px #fff, 0 -2px #fff,
    1px 1px #fff, -1px -1px #fff, 1px -1px #fff, -1px 1px #fff;
    font-size: 128px;
    //position: relative;
    display: flex;
    justify-content: center;
    align-items: center;
    background-image: url(${FieldImg});
`;

export default WaitingBox;