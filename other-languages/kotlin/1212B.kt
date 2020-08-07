import java.util.*;


fun main(args: Array<String>) {
    var sc = Scanner(System.`in`);
    var n:Int = 0;
    var s:String = "";
    var maximus:Int = 0;
    var temp:Int = 0;

    n = sc.nextInt();
    s = sc.nextLine();
    s = sc.nextLine();

    var t:String="";
    var r:String="";
    var res:String = "";
    
    for(i in 0..(n-2) ){
        t = s.substring(i,i+2);
        temp = 0;
        for( j in 0..(n-2)){
            r = s.substring(j,j+2);
            if(t.equals(r)){    temp++; }
        }
        if(temp>maximus){   maximus = temp; res = t; }
    }


    println(res);

    sc.close();    
}