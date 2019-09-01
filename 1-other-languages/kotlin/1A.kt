import java.util.*;
import kotlin.math.*;

fun main(args: Array<String>) {
    var sc = Scanner(System.`in`);

    var a:Long = 0;
    var b:Long = 0;
    var arr = Array<Long>(3){0};
    
    // var i:Long=0;
    
    for(i in 0..2){
        arr[i] = sc.nextLong();
        //arr[0] = sc.nextLong();arr[1] = sc.nextLong();arr[2] = sc.nextLong();
    }
    var zero:Long = 0;

    a = arr[0]/arr[2]; if(arr[0]%arr[2]!=zero){    a++; }
    b = arr[1]/arr[2]; if(arr[1]%arr[2]!=zero){    b++; }

    a = a*b;

    println(a);

    //a = sc.nextLong();
    //prLongln(a);

    sc.close();
}