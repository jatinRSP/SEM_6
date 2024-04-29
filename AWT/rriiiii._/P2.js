// const {add, sub, mul, div} = require('./calc.js');
const calc = require('./calc.js');

const a = 2;
const b = 3;

console.log("add",calc.add(a,b));
console.log(`Sub: ${calc.sub(a,b)}`);
console.log(`Mul: ${calc.mul(a,b)}`);
console.log(`Div: ${calc.div(a,b)}`);

