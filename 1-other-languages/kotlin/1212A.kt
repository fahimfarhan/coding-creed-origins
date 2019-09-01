import java.util.*;

fun main(args: Array<String>) {
    var n:Long = 0;
    var k:Long = 0;
    var zero:Long = 0;

    var sc = Scanner(System.`in`);
    n = sc.nextLong();
    k = sc.nextLong();

    for(i in 1..k){
        if( (n%10) == zero ){  n = n/10;   }
        else{   n = n-1; }
    }

    println(n);
}