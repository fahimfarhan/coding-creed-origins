import java.util.*;

public class B911{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int a,b,n;
        n = sc.nextInt();
        a = sc.nextInt();
        b = sc.nextInt();

        int ans=0;
        for(int i=1; i<n; i++){
            int temp1 = a/i; int temp2 = b/(n-i);
            if(temp2<temp1){temp1 = temp2; }
            if(temp1>ans){ ans = temp1; }
        }
        System.out.println(ans);
        sc.close();
    }
}