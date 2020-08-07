import java.util.*;
import kotlin.math.*;

fun main(args: Array<String>){
    var sc = Scanner(System.`in`);

    var a:Int = 0;
    // var b:Int = 0;
    // var c:Int = 0;
    // var i:Int = 0;
    
    var myArray = Array<Int>(4){0};

    for(i in 0..3){
        myArray[i] = sc.nextInt();    
    }

    myArray.sort();
    for(i in 0..2){
        a = myArray[3] - myArray[i];
        println(a);
    }

}