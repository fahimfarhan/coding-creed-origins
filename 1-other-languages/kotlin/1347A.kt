import java.util.*;
import kotlin.math.*;

fun main(args : Array<String>) {

    var sc = Scanner(System.`in`);
    var a   :   Int;
    var b   :   Int;
    var sum :   Int;
    var t   :   Int;

    t = sc.nextInt();
    for(i in 1..t) {
        a = sc.nextInt(); b = sc.nextInt();
        sum = a + b;
        println(sum);
    }

    sc.close();
} 