import React, { useEffect, useState, useRef } from 'react';
import styled from 'styled-components';
import ballImg from '../img/Ball.png';

const BALL_RADIUS = 10;
const BALL_SIZE = BALL_RADIUS * 2;
const BASE_VELOCITY = 2;
const HEIGHT_OFFSET = 30;
const MAX_VELOCITY = 6;
const BOUNCE_ACCELERATION = 1.1;

const Ball = (props) => {
    const [position, setPosition] = useState({
      x: props.width / 2,
      y: props.height / 2
    });
  
    const [velocity, setVelocity] = useState({
      x: BASE_VELOCITY,
      y: BASE_VELOCITY
    });
  
    const ballRef = useRef(null);

    useEffect(() => {
      let intervalId = setInterval(() => {
        if (props.managerRef.current && props.managerRef.current.innerText === "")
        {
            setPosition((prevPosition) => ({
              x: prevPosition.x + velocity.x,
              y: prevPosition.y + velocity.y
            }));
        }
      }, 4);  
      return () => clearInterval(intervalId);
    }, [velocity, props.managerRef, props.height, props.width]);
  
    const [isColliding, setIsColliding] = useState(false);

    useEffect(() => {
      if (position.x <= 0 + 10 || position.x + BALL_SIZE >= props.width - 10) {
        setVelocity((prevVelocity) => ({
          x: prevVelocity.x < 0 ? -BASE_VELOCITY : BASE_VELOCITY,
          y: BASE_VELOCITY
        }));
        setPosition((prevPosition) => ({
          x : props.width / 2,
          y: props.height / 2
        }))
        if (position.x <= 0 + 10)
        {
          const currValue = parseInt(props.scoreRight.current.innerText);
          props.scoreRight.current.innerText = currValue + 1 < 10 ? '0' + (currValue + 1) : currValue + 1;
        }
        else
        {
          const currValue = parseInt(props.scoreLeft.current.innerText);
          props.scoreLeft.current.innerText = currValue + 1 < 10 ? '0' + (currValue + 1) : currValue + 1;
        }
      }
      if (position.y <= 0 + HEIGHT_OFFSET || position.y + BALL_SIZE >= props.height - HEIGHT_OFFSET) {
        if (!isColliding) {
          setIsColliding(true);
          setVelocity((prevVelocity) => ({
              x: prevVelocity.x,
              y: -prevVelocity.y
          }));
      } else {
        setIsColliding(false);
      }
      }
      const ballRect = ballRef.current.getBoundingClientRect();
      
      const checkCollision = (ballRect, characterRect) => {
        
        if (ballRect.x + BALL_RADIUS > characterRect.x &&
          ballRect.x - BALL_RADIUS < characterRect.x + characterRect.width &&
          ballRect.y + BALL_RADIUS > characterRect.y &&
          ballRect.y - BALL_RADIUS < characterRect.y + characterRect.height)
          return (true)
        return (false)
      }

      const playerRect = props.playerRef.current && props.playerRef.current.getBoundingClientRect();
      const opponentRect = props.opponentRef.current && props.opponentRef.current.getBoundingClientRect();
      if ((props.playerRef.current && checkCollision(ballRect, playerRect)) ||
        (props.opponentRef.current && checkCollision(ballRect, opponentRect))) {
        if (!isColliding) {
          setIsColliding(true);
          setVelocity((prevVelocity) => ({
              x: -(prevVelocity.x < 0 ? (Math.max(prevVelocity.x * BOUNCE_ACCELERATION, -MAX_VELOCITY)) :
                  Math.min(prevVelocity.x * BOUNCE_ACCELERATION, MAX_VELOCITY)),
              y: prevVelocity.y
          }));
        }
      } else {
        setIsColliding(false);
      }
    }, [position, props.playerRef, props.opponentRef, props.scoreLeft, props.scoreRight, props.height, props.width, isColliding]);
  
    return (
      <BallDiv ref={ballRef} x={position.x} y={position.y} />
    );
  };

const BallDiv = styled.div.attrs(props => ({
style: {
    width: `${BALL_RADIUS * 2}px`,
    height: `${BALL_RADIUS * 2}px`,
    left: `${props.x - BALL_RADIUS}px`,
    top: `${props.y - BALL_RADIUS}px`,
    backgroundImage: `url(${ballImg})`
}
}))`
position: absolute;
background-size: cover;
background-position: center;
// border-radius: 50%;
`;

export default Ball;
