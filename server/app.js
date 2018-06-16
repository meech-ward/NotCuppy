const SerialPort = require('serialport');

const baudRate = 9600;

const states = {
  stop: 0, forwards: 1, left: 2, right: 3, backwards: 4
};
exports.states = states;

const port = new SerialPort('/dev/cu.usbmodem14521', {
  baudRate
});

// Open errors will be emitted as an error event
port.on('error', function(err) {
  console.log('Error: ', err.message);
})

function updateState(state) {
  let hex  = Number(state).toString(16);
  hex = hex.length > 1 ? hex : `0${hex}`;
  const value = new Buffer(hex, 'hex');
  port.write(value, (err) => {
    if (err) {
      return console.log('Error on write: ', err.message);
    }
    console.log('message written');
  });
  console.log(hex, value);
}
exports.updateState = updateState;


 
