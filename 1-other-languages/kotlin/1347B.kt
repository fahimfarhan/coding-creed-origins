import java.util.*;
import kotlin.math.*;

fun main(args : Array<String>) {
    var a1:Int;
    var b1:Int;
    var a2:Int;
    var b2:Int;

    var t:Int;
    var sc = Scanner(System.`in`);

    t = sc.nextInt();

    for(i in 1..t) {
        a1 = sc.nextInt(); b1 = sc.nextInt();
        a2 = sc.nextInt(); b2 = sc.nextInt();

        if(b1 > a1) {
            a1 = a1 xor b1;  
            b1 = a1 xor b1;  
            a1 = a1 xor b1; 
        }

        if(b2 > a2) {
            a2 = a2 xor b2;    
            b2 = a2 xor b2;    
            a2 = a2 xor b2;
        }

        if( (a1 == a2) && ( (b1+b2) == a1)) {
            println("Yes");
        }else{
            println("No");
        }
    }

    sc.close();
}