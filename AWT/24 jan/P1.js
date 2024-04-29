// Code for printing current date time using custom node module not to use inbuilt module
// Date of creation: 24/1/2019

// Including the readline module from package
const readline = require('readline');

// Including the custom module
const dateTime = require('./dateTime');

// Creating the interface
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

// Calling the function from custom module
dateTime.dateTime();

// Closing the interface
rl.close();

// End of code

