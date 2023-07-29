import styled from 'styled-components';
import GameModeManager from './components/GameModeManager';

const GAME_WIDTH = 991;
const GAME_HEIGHT = 678;

function App() {
 return (
    <Div>
      <GameModeManager height={GAME_HEIGHT} width={GAME_WIDTH}/>
    </Div>
  
 )
}

export default App;

const Div = styled.div`
  display: flex;
  width: 100%;
  justify-content: center;
`;
