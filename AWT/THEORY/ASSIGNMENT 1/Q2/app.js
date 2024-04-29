const fs = require('fs');
const readline = require('readline');
function copyFile(inputFilePath, outputFilePath) {
    const inputStream = fs.createReadStream(inputFilePath);
    const outputStream = fs.createWriteStream(outputFilePath);
    const rl = readline.createInterface({
        input: inputStream,
        crlfDelay: Infinity
    });
    rl.on('line', (line) => {
        outputStream.write(`${line}\n`);
    });
    rl.on('close', () => {
        outputStream.end();
        console.log('File copied successfully.');
    });
}
const inputFilePath = 'input.txt';
const outputFilePath = 'output.txt';
copyFile(inputFilePath, outputFilePath);
