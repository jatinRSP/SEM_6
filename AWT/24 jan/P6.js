// Read file from the file system

const fs = require('fs');
const path = require('path');
const http = require('http');
const https = require('https');

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
});locationbarll