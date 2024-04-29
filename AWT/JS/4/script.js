const age = 17;

if (age >= 18) {
    console.log('You are an adult');
} else {
    console.log('You are a minor');
}

// if 
// else if
// else

// ternary operator

age >= 18 ? console.log('You are an adult') : console.log('You are a minor');

// switch

const day = 69;

switch (day) {
    case 1:
        console.log('Monday');
        break;
    case 2:
        console.log('Tuesday');
        break;
    case 3:
        console.log('Wednesday');
        break;
    case 4:
        console.log('Thursday');
        break;
    case 5:
        console.log('Friday');
        break;
    case 6:
        console.log('Saturday');
        break;
    case 7:
        console.log('Sunday');
        break;
    default:
        console.log('Invalid day');
        break;
}