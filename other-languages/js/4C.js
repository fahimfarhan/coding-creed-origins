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
    var N, username, temp, j;
    mp = {};
    N = parseInt(readLine());

    for(var i=0; i<N; i++){
        username = readLine();
        if(mp[username]){
            j = mp[username];
            j = j.toString();
            temp = username+j;
            console.log(temp);
            mp[username]+=1;

        }else{
            console.log("OK");
            mp[username] = 1;
        }
        
    }


    //var res = 0;
    //console.log(res);
}

