import java.util.*;
import kotlin.math.*;

fun main(Args:Array<String>){
    var sc = Scanner(System.`in`);

    var n:Int = 0;
    var curr:Int = 0;
    var kount:Int = 0;
    var a:Array<Int>;

    n = sc.nextInt();
    kount = n;
    a = Array<Int>(n){0};
    
    for(i1 in 0..(n-1)){
        a[i1] = sc.nextInt();
    }

    for(i in (n-1) downTo 0){
        if(a[i]!=-1){
            curr = a[i];
            for(j in (i-1) downTo 0){
                if(a[j] == curr){
                    kount--;
                    a[j] = -1;
                }
            }
        }
    }


    println(kount);
    for(i in 0..(n-1)){
        if(a[i]!=-1){
            print(a[i]);
            print(" ");
        }
    }
    println("");

}