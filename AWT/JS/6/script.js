// LOOPS

// for loop

let i;

for (i = 0; i < 5; i++) {
    console.log("jatin",i);
}

// while loop

// let j = 1234;

// while (j > 0) {
//     consol.log(j%10);
//     j = parseInt(j/10);
// }

// do while loop

let number = 30;
let guess;

do {
    guess = parseInt(prompt("Guess the number"));
} while (guess != number);

console.log("Congrats! You guessed the number");
