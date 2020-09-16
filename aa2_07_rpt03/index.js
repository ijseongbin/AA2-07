//http server : index.js
var http = require ("http");
port = 3003;

var server = http.createServer((request, response ) => {
    response.writeHeader(200, {
        "Content-Type": "text/plain",
    });
    response.write("Hello HTTP server frome node.js"); //WEB response
    response.write("\n");
    response.write("My ID is aa2-07! \n");
    response.end();
});

server.listen(port);
console.log("Server Running on " + port + ".\nLaunch http://localhost:" + port)