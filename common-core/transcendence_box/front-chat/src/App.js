import Pusher from "pusher-js";
import { useEffect, useState } from "react";

function App() {
  const [username, setUsername] = useState('username')
  const [messages, setMessages] = useState([]);
  const [message, setMessage] = useState('');
  
  let allMessages = [];

  useEffect(() => {
    Pusher.logToConsole = true;

    var pusher = new Pusher('31ea48981079b0b4e216', {
      cluster: 'eu'
    });

    var channel = pusher.subscribe('chat');
    channel.bind('message', function(data) {
      allMessages.push(data);
      setMessages(allMessages);
    });
  }, []);

  const submit = async e => {
    e.preventDefault();

    await fetch('http://localhost:8000/api/messages', {
      method: 'POST',
      headers: {'Content-Type': 'application/json'},
      body: JSON.stringify({
          username,
          message
        })
      });
    
    setMessage('');
  }

  return (
    <div className="container">    
      <div className="d-flex flex-column align-items-stretch flex-shrink-0 bg-body-tertiary">
      <div href="/" 
      className="d-flex align-items-center flex-shrink-0 p-3 link-body-emphasis text-decoration-none border-bottom">
        <input className="fs-5 fw-semibold" value={username} onChange={e => setUsername(e.target.value)}></input>
      </div>
      <div className="list-group list-group-flush border-bottom scrollarea">
        {messages.map(message => {
          return (
              <div className="list-group-item list-group-item-action py-3 lh-sm">
                <div className="d-flex w-100 align-items-center justify-content-between">
                  <strong className="mb-1">{message.username}</strong>
                </div>
              <div className="col-10 mb-1 small">{message.message}</div>
            </div>
          )
        })}
        
      </div>
      </div>
      <form onSubmit={submit}>
        <input className="form-control" placeholder="Write a message" value={message}
          onChange={e => setMessage(e.target.value)}
        />
      </form>
    </div>

  );
}

export default App;
