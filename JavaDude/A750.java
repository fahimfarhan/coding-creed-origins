import java.util.*;

public class A750{

    public static void main(String[] Args){
        Scanner sc = new Scanner(System.in);

        int n,k;
        n = sc.nextInt();
        k = sc.nextInt();
        int i=0;
        for(i=0; i<n; i++){
            k = k + 5*(i+1);
            if(k>240){  break;  }
        }
        System.out.println(i);
    }
}