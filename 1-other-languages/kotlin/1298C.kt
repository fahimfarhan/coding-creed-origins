import java.util.*;
import kotlin.math.*;

fun main(Args:Array<String>){
    var sc = Scanner(System.`in`);
    var n:Int = 0;
    var kount:Int = 0;
    var s:String = "";

    n = sc.nextInt();
    s = sc.next();

    // println(n);
    // println(s);

    for(i in 0..(n-3)){
        if( (s[i]=='x') &&(s[i+1]=='x') &&(s[i+2]=='x')){
            // s[i] = 'A';
            kount++;
        }
    }

    println(kount);



}