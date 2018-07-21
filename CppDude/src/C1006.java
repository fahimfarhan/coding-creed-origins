import java.util.*;

public class C1006{
    public static void main(String[] Args){
        int n;
        long []a;
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        
        a = new long[n+1];
        
        for(int i=01; i<=n; i++){
            a[i] = sc.nextLong();
        }

        long sum1, sum2, mx;
        sum1=0; sum2=0; mx=0;
        Map<Long, Integer> mp = new HashMap<Long, Integer>();

        for(int i=1; i<=n; i++){
            sum1 = sum1 + a[i];
            mp.put(sum1, i);
        }

        for(int i=n; i>=1; i--){
            sum2 = sum2 + a[i];
            try{
                    int j = mp.get(sum2);    //.getValue();
                    if(j<=i){
                    //mx = max(mx, sum2);
                    if(sum2>mx){    mx = sum2;  }
                }
            }
            catch(Exception x){

            }
            
        
        }

        System.out.println(mx); 

        sc.close();
    }
}