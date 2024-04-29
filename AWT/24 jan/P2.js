var http = require('http');

// Code for getting header information from request

// Creating the server
http.createServer(function (req, res) {
    // Writing the header information
    res.writeHead(200, {'Content-Type': 'text/html'});
    // Writing the response
    console.log(req.headers);f
    res.end('Hello World!');
}).listen(3000);