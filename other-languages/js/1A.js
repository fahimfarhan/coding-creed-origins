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

function solveMeFirst(a, b, c) {
  // Hint: Type return a+b below   
    var ret = 0;
    ret = Math.ceil(a/c)*Math.ceil(b/c);
    return ret;
}


function main() {
    var a, b; 
    var c, d, e;
    e = readLine();
    d = e.toString().split(' ');
    a = parseInt(d[0]); b = parseInt(d[1]); c = parseInt(d[2]);

    var res = solveMeFirst(a, b, c);
    console.log(res);
}

