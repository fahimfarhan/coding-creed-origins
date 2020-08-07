import java.util.*;
import kotlin.math.*;

fun main(args:Array<String>){
    var sc = Scanner(System.`in`)
    var n:Int = 0;
    var a:Int = 0;
    var myArray:Array<Int>;

    n = sc.nextInt();
    myArray = Array<Int>(n){0};

    for(i in 0..(n-1)){
        myArray[i] = sc.nextInt();
    }

    var mySet = HashSet<Int>();
    
    for(i in (n-1) downTo 0){
        mySet.add(myArray[i]);
    }

    // println(mySet);

    for(i in (mySet.size-1) downTo 0){
        a = mySet.elementAt(i);
        print(a);
        print(" ");
    }
    println("");
    
}