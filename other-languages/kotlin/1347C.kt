import java.util.*;
import kotlin.math.*;

fun main(args : Array<String>) {
    var sc = Scanner(System.`in`);
    
    var t:Int;
    var n:Int;
    var s:String;
    var kount:Int;
    var d:Int;

    t = sc.nextInt();
    
    s = sc.nextLine(); // todo: cz after reading t, we are still in the same line. this line segment
    // is calculated and so we get a 0 at beginning. to remove the 0, adding this line
    for( t1 in 1..t) {
        // n = sc.nextInt();
        s = sc.nextLine();
        n = s.length;
        d = 1;
        var v = ArrayList<Int>();
        var temp:Int;

        for(j in 1..n) {
            var i:Int;
            i = n - j;
            if(s[i]!='0') {
                temp = s[i]-'0';
                temp = temp*d;
                v.add(temp);
            }
            d = d*10;
        }

        kount = v.size;
        println(kount);
        for(i in 0..(kount-1)) {
            print(""+v[i]+" ");
        }
        println("");
    }

    sc.close();
}