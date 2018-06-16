const express = require('express');
const app = require('./app');

const server = express();

server.get('/', (req, res) => {
  res.send("🤗");
});

server.post('/forwards', (req, res) => {
  app.updateState(app.states.forwards);
  res.send("🤗");
});
server.post('/left', (req, res) => {
  app.updateState(app.states.left);
  res.send("🤗");
});
server.post('/right', (req, res) => {
  app.updateState(app.states.right);
  res.send("🤗");
});
server.post('/backwards', (req, res) => {
  app.updateState(app.states.backwards);
  res.send("🤗");
});
server.post('/stop', (req, res) => {
  app.updateState(app.states.stop);
  res.send("🤗");
});

server.listen(4000, () => console.log("😎"));