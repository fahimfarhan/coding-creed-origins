process.stdin.resume();
process.stdin.setEncoding('ascii');

var input_stdin = "";
var input_stdin_array = "";
var input_currentline = 0;

process.stdin.on('data', function (data) {
    input_stdin += data;
});

process.stdin.on('end', function () {
    input_stdin_array = input_stdin.split("\n");
    main();    
});

function readLine() {
    return input_stdin_array[input_currentline++];
}



function main() {
    var res=0;
    var N = 0;
    var arr = [];

    N = parseInt(readLine());

    for(var i=0; i<N; i++){ res = parseInt(readLine()); arr.push(res);   }

    arr.sort();
    var minimus, maximus;

    minimus = arr[0];
    maximus = arr[N-1];

    if(minimus == 7){    console.log("Case 1");    }
    else if(minimus > 7){   console.log("Case 2");   }
    else{   console.log("Case 3");  }

    console.log(minimus);
    console.log(maximus);
}

