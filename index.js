const http = require('http')
const express = require('express') //**express */
const Socket = require('socket.io')//** socket.io */

const app = express()//**init express */
const server = http.createServer(app);//**created server
const io = Socket.listen(server)//**init socket.io *//

app.use(express.static(__dirname + '/public'));//** ubication the files public */
server.listen(3000, () => console.log('server on port 3000'));


const {SerialPort} = require('serialport');
const {ReadlineParser} = require('@serialport/parser-readline')


const port = new SerialPort({ path: '/COM4', baudRate: 9600 })

  const parser = port.pipe(new ReadlineParser({ delimiter: '\r\n' }));

  parser.on('open', function () {
    console.log('connection is opened');
  });
  
  parser.on('data', function (data) {
    let temp = parseInt(data, 10) + " °C";
    console.log(temp);
    io.emit('temp', data.toString());
  });
  
  parser.on('error', (err) => console.log(err));
  port.on('error', (err) => console.log(err));