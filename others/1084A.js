//var input = readline()
var k = readline()
var n = parseInt(k)
var a = readline().split(' ')

var sum = 0;
for(var i=0; i<n; i++){
    sum+=(i*4)*a[i];
}
print(sum)