import java.util.*;

public class Context{
    public static void main(String[] Args){
        Strategy s1 = new AlgoA();
        Strategy s2 = new AlgoB();
        
        Customer c1 = new Customer(s1);
        Customer c2 = new Customer(s2);

    }
}