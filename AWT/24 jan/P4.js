var express = require('express');

// var app = express();
//     use(function(req, res) {
//         res.cookie('name', 'foo');
//         res.end('Hello World');
//     })
//     .listen(3000, () => console.log('Server is running on http://localhost:3000/'));

var app = express();
app.use(function(req, res) {
    res.cookie('name', 'foo');
    res.end('Hello World');
});
app.listen(3000, () => console.log('Server is running on http://localhost:3000/'));