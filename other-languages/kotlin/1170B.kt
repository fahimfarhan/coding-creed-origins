import java.util.*;

fun main(args : Array<String>){

    var n:Int = 0; var a:Int = 0; var b:Int = 0; var c:Int = 0;
    var x:Int = 0; var y:Int = 0;
    var sc = Scanner(System.`in`);
    var temp:Int=0;

    n = sc.nextInt();
    var myarray = Array<Int>(n+1){0};
    //q = sc.nextInt();

for( i in 0..n ){
    myarray[i] = sc.nextInt();
}

    y=0;
    for( i in 0..n ){
        a = myarray[i];
        x = 0;
        if(a == 7){ y++; continue; }
        else{
            c = i-1;
            for(j in 0..c){
                b = myarray[j];
                if(b>a){
                    x=x+1;
                    if(x>=2){   y=y+1; }
                    break;
                }
            }
        }
        
    }

    println("$y");


    sc.close();

}