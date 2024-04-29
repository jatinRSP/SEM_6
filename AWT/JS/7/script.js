function hello () {
    console.log("Hello World");
}

function add (a,b) {
    return a+b;
}


// Function that add infinite numbers
// arguments is a special keyword that is an array of all the arguments passed to the function

function addNumbers () {
    let ans = 0;

    for (let i = 0; i < arguments.length; i++) {
        ans += arguments[i];
    }

    return ans;
}


console.log(addNumbers(1,2,3,4,5,6,7,8,9,10));

// spread operator

function addNumbersSpread (...args) {
    let ans = 0;

    for (let i = 0; i < args.length; i++) {
        ans += args[i];
    }

    return ans;
}

console.log(addNumbersSpread(1,2,3,4,5,6,7,8,9,10));