import java.util.*;
import kotlin.math.*;

fun main(args: Array<String>) { 

    var sc = Scanner(System.`in`);
    // var a:Int = 0;

    // a = sc.nextInt();
    // println(a);
    
    // println("Hello, World!"); 
    
    var n: Int = 0;
    n = sc.nextInt();

    var a: ArrayList<Int> = ArrayList<Int>();
    var m: Int = 0;
    for(i in 1..n) {
      m = sc.nextInt();
      a.add(m);
    }

    var mp: TreeMap<Int, Boolean> = TreeMap<Int, Boolean>();
    var myStack: Stack<Int> = Stack<Int>();

    for(j in 0 .. (n-1)) {
      var i = (n - 1) - j;
      if(mp[a[i]] == null || mp[a[i]] == false) {
        myStack.push(a[i]);
        mp[a[i]] = true;
      }
    }

    println(myStack.size)

    while(!myStack.empty()) {
      print(""+myStack.pop()+" ")
      // myStack.pop()
    }
    
    sc.close();
}

// kotlinc hello.kt -include-runtime -d hello.jar
// java -jar hello.jar