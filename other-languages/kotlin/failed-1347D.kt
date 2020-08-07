import java.util.*;
import kotlin.math.*;

fun main(args : Array<String>) {
    var sc = Scanner(System.`in`);

    var T:Int;
    var n:Int;
    var a:Int;
    var b:Int;
    var c:Int;
    var p1:Int;
    var p2:Int;
    var kount:Int;

    T = sc.nextInt();
    for(t in 1..T) {
        a = 0; b = 0; kount = 0;
        var list = ArrayList<Int>();

        n = sc.nextInt();
        for(i in 1..n) {
            c = sc.nextInt();
            list.add(c);
        }

        p1 = 0;
        p2 = n-1;
        while(p1 <= p2) {
            var bool = false;

            while( (a <= b) && (p1 <= p2) ) {
                a  = a  + list[p1];
                p1 = p1 + 1;
                bool = true;
            }
            if(bool == true){  kount = kount+1;    }

            bool = false;
            while( (b <= a) && (p1 <= p2) ) {
                b  = b  + list[p2];
                p2 = p2 - 1;
                bool = true;
            }
            if(bool == true){  kount = kount+1;    }
        }

        print(kount); print(" "); print(a); print(" "); println(b);
    }

    sc.close();
}