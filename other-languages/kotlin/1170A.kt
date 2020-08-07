import java.util.*;

fun main(args : Array<String>){

    var q:Int = 0; var a:Int = 0; var b:Int = 0; var c:Int = 0;
    var x:Int = 0; var y:Int = 0;
    var sc = Scanner(System.`in`);
var temp:Int=0;
    q = sc.nextInt();

    c = 1;
    while(q>0){
        x = sc.nextInt(); y = sc.nextInt();
        if(y>x){
            temp = y; y = x; x = temp;
        }
        b = y-c;
        a = x-b;

        println("$a $b $c");
        q=q-1;
    }

    sc.close();

}