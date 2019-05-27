import java.util.*;


fun main(args: Array<String>){
    var sc = Scanner(System.`in`);

    var y:Int = sc.nextInt();
    var b:Int = sc.nextInt()
    var r:Int = sc.nextInt()
    
    var maximus:Int = 0;
    var temp:Int = 0;

    var minimus:Int = 1000;

    // if(y<minimus){  minimus = y; }
    // else if(b<minimus){ minimus=b; }
    // else if(r<minimus){ minimus=r; }

    for( i in 0..b ){
        if((i+1<=r) && (i-1<=y)){
            maximus = i+1 + i + i-1;
        }
    }
    println("$maximus");
    sc.close();
}
