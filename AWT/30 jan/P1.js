const express = require('express');
const https = require('https');
const fs = require('fs');

const app = express();
const portHTTP = 3000;
const portHTTPS = 3443; // Use a different port for HTTPS

// Middleware to redirect HTTP to HTTPS
app.use((req, res, next) => {
  if (req.protocol === 'http') {
    res.redirect(`https://${req.hostname}:${portHTTPS}${req.url}`);
  } else {
    next();
  }
});

app.get('/', (req, res) => {
  res.send('Hello, this is the homepage!');
});

app.get('/about', (req, res) => {
  res.send('Welcome to the about page!');
});

app.get('/user/:id', (req, res) => {
  const userId = req.params.id;
  res.send(`User ID: ${userId}`);
});

app.get('/search', (req, res) => {
  const query = req.query.q;
  res.send(`Search query: ${query}`);
});

// HTTPS configuration
const httpsOptions = {
  key: fs.readFileSync('path/to/private-key.pem'),
  cert: fs.readFileSync('path/to/certificate.pem'),
};

// Create an HTTPS server
const serverHTTPS = https.createServer(httpsOptions, app);

// Start the HTTP server
app.listen(portHTTP, () => {
  console.log(`HTTP server is listening at http://localhost:${portHTTP}`);
});

// Start the HTTPS server
serverHTTPS.listen(portHTTPS, () => {
  console.log(`HTTPS server is listening at https://localhost:${portHTTPS}`);
});
