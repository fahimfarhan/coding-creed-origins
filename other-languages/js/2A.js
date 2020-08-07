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


function winner(arr){
    var hash = {};
    var round = [];
    var username, newPoint;
    var maximus = -1;
    var victorious = "";
    for(var str of arr){
        var temp = str.split(' ');
        username = temp[0];
        newPoint = parseInt(temp[1]);

        var point = 0;
        point = hash[username]?(hash[username]+newPoint):newPoint;
        hash[username] = point;
        
        if(point > maximus){
            victorious = username;
            maximus = point; 
        }

    }

    return victorious;
}

function main() {
    var N = readLine();
    N = parseInt(N);

    var arr = [];
    for(var i=0; i<N; i++){
        var str = readLine();
        arr.push(str); // arr.push(str);
    }

    var res = winner(arr);

    console.log(res);
}

