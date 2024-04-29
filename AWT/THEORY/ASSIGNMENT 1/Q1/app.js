const calculator = require('./calculator');
const sum = calculator.add(14, 2);
console.log(`Sum: ${sum}`);
const difference = calculator.subtract(8, 4);
console.log(`Difference: ${difference}`);
const product = calculator.multiply(2, 6);
console.log(`Product: ${product}`);
const quotient = calculator.divide(10, 2);
console.log(`Quotient: ${quotient}`);