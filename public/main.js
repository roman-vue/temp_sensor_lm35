
const socket = io();

console.log(socket);
const temperatureDisplay = document.getElementById('temperature');

socket.on('temp', function (data) {
  console.log(data);
  temperature.innerHTML = `${data}°C`;
});