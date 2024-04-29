console.log('HELLO WORLD');

const a = 3 // Ek vaar value aapi didhi pachi change na thaay
let b = 5 // Let matlab hu aagad jayine bijo variable na banai saku b naam no
var c = 10 // Aagad jayine pan c naam no variable banai saku

/////////////////////////////////

for(let i = 0; i<5 ; i++){
    console.log("Hello",i)
}

let nameeee = "JATIN"

for(let c in nameeee){  // AA aapdne index return karse iteretable entity na object or we can say iteretable entity na object ni key 
    console.log(nameeee.charAt(c))
}

for(let c of nameeee){ // AA aapdne direct iteratable entity na object ni value return karse
    console.log(c)
}

/////////////////////////////////

[1,2,3,4,5,6,7,8,9,10].forEach((element,index,list)=>{
    console.log(list[index]);
});

/////////////////////////////////

['a','b','c','d'].forEach((element,index)=>{
    console.log(element);
});

/////////////////////////////////

let j = 0;

while (j<3){
    console.log(j);
    j++
}

/////////////////////////////////

do {
    console.log(j);
    j++
} while (j<5);

/////////////////////////////////

function add(a,b){
    return a+b;
}

console.log(add(5,6));

/////////////////////////////////

let addd = (a,b) => {return a+b};

console.log(addd(5,6));

/////////////////////////////////








