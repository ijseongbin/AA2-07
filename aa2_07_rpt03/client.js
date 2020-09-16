//tcp client
var net = require("net");
var port = 3000;
var client = new net.Socket();

//Connection using socket
client.connect(port, "127.0.0.1");
//Receive data from socket, callback function
client.on("data", (data) =>{
    console.log("Data: " + data);
    console.destroy();
});
//Add a 'close' event hadler for the client socket
client.on("close", () => {
    console.log("Connection closed");
});