import React, { useEffect, useState } from 'react';
import styled from 'styled-components';

const START_TIMER = 3;

const GameManager =  React.forwardRef((props, ref) =>  {
    const [timer, setTimer] = useState(START_TIMER);

    useEffect(() => {
        let intervalId;
        if (timer > 0)
        {
            intervalId = setInterval(() => {
                setTimer(timer - 1);
              }, 1000);
            if (ref.current)
                ref.current.innerText = "Ready \n\t " + timer
        }
        else if (ref.current && !ref.current.innerText.includes("Click to play"))
        {
            intervalId = setInterval(() => {
                if (props.scoreRight.current.innerText === "10")
                    ref.current.innerText = "J2 wins ! \n Click to play"
                else if (props.scoreLeft.current.innerText === "10")
                    ref.current.innerText = "You win ! \n Click to play"
                else
                    ref.current.innerText = ""
            }, 10);
        }
        return () => clearInterval(intervalId);
      }, [timer, ref, props.scoreLeft, props.scoreRight]);

      const HandleReplay = () => { 
        if (ref.current.innerText.includes("Click to play"))
        {
            props.scoreLeft.current.innerText = "00";
            props.scoreRight.current.innerText = "00";
            setTimer(START_TIMER);
        }
      }
    
      return (
        <GameManagerDiv onClick={HandleReplay} ref={ref} width={props.width} height={props.height}></GameManagerDiv>
        )

      
})

const GameManagerDiv = styled.div`
  height: 200px;
  width: 1500px;
  left: -250px;
  text-align: center;
  top: ${(props) => (props.height / 2) - 150}px;
  color: red;
  @font-face {
    font-family: 'Keania One';
    src: url('../font/KeaniaOne-Regular.ttf') format('truetype');
    font-weight: normal;
    font-style: normal;
  };
  text-shadow: 2px 0 #fff, -2px 0 #fff, 0 2px #fff, 0 -2px #fff,
               1px 1px #fff, -1px -1px #fff, 1px -1px #fff, -1px 1px #fff;
  font-family: 'Keania One', sans-serif;
  font-size: 128px;
  position: absolute;
`;

export default GameManager;