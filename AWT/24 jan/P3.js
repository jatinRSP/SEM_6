const http = require('http');
const https = require('https');
const fs = require('fs');

// Read SSL certificate and key files for HTTPS
const privateKey = fs.readFileSync('path/to/private-key.pem', 'utf8');
const certificate = fs.readFileSync('path/to/certificate.pem', 'utf8');
const credentials = { key: privateKey, cert: certificate };

// Create HTTP server
const httpServer = http.createServer((req, res) => {
  res.writeHead(200, { 'Content-Type': 'text/plain' });
  res.end('Hello, World! (HTTP)\n');
});

// Create HTTPS server
const httpsServer = https.createServer(credentials, (req, res) => {
  res.writeHead(200, { 'Content-Type': 'text/plain' });
  res.end('Hello, World! (HTTPS)\n');
});

// Set the port numbers for HTTP and HTTPS servers
const httpPort = 8080;
const httpsPort = 8443;

// Listen on specified ports
httpServer.listen(httpPort, () => {
  console.log(`HTTP server listening on port ${httpPort}`);
});

httpsServer.listen(httpsPort, () => {
  console.log(`HTTPS server listening on port ${httpsPort}`);
});
