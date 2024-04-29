// Syntax of Arrow Function

const hello = () => {
    console.log("Hello World");
}

const add = (a,b) => {
    return a+b;
}

// Arrow function for single line return

const add2 = (a,b) => a+b;

hello();
console.log(add(2,3));
console.log(add2(2,3));

// Arrow function ma arguments keyword nathi
// Arrow function ma jo infinite argument leva hoy to spread operator use kari sakay

const addNumbers = (...args) => {
    let ans = 0;

    for (let i = 0; i < args.length; i++) {
        ans += args[i];
    }

    return ans;
}

console.log(addNumbers(1,2,3,4,5,6,7,8,9,10));

// Hoisting bworks in normal function but not in arrow function

heyyyy();

function heyyyy () {
    console.log("Hello World");
}

////////////////////////////

// heyyyy2(); // Error

const heyyyy2 = () => {
    console.log("Hello World");
}

heyyyy2();