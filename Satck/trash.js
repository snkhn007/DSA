function outer() {
    let x = 10;

    function inner() {
        console.log(x);
    }

    return inner;
}

let f = outer();
f();


// console.log("x outside all the funtions: "+ x);