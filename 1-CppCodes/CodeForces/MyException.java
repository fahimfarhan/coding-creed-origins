import java.util.*;

public class MyException{
    public static void main(String[] Args){

        int n,m;
        n = 1; m=0;
        try{
            System.out.println("here1\n");
            n = n/m;
            System.out.println("here2\n");
        }catch(Exception x){
            System.out.println("here3\n");
            n = n/m;
            System.out.println("here4\n");
        }finally{
            System.out.println("here5\n");
            n = n/m;
            System.out.println("here6\n");
        }
    }
}