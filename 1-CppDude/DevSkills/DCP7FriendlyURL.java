import java.util.*;

public class DCP7FriendlyURL{
    
    public static void main(String[] Args){
        Scanner sc = new Scanner(System.in);

        int T, n;
        String s;
        T = sc.nextInt();
        while(T>0){
            T--;
            n  = sc.nextInt();
            s = sc.nextLine();

            s = s.toLowerCase(); // 1
            // 2
            for(int i=0; i<s.length(); i++){
                if( !('A' <= s.charAt(i) && s.charAt(i) <='Z')
                || !('a' <= s.charAt(i) && s.charAt(i) <='z')
                || !('0' <= s.charAt(i) && s.charAt(i) <='9')  ){
                    
                    StringBuilder sb = new StringBuilder(s);
                    sb.setCharAt(i, '-');
                    s = sb.toString();
                }
            }
            // 3
            for(int i=0; i<s.length()-1; i++){
                if( s.charAt(i) == '-' && s.charAt(i+1) == '-' ){
                    s = s.substring(0,i)+s.substring(i+1);
                }
            }
            // 4 
            if(s.charAt(0) == '-'){ s = s.substring(1); }
            if(s.charAt(s.length()-1) == '-' ){ s = s.substring(0,s.length()-1);  }
            //5 
            for(int i=0; i<s.length(); i++){
                if(s.charAt(i) == '\t'){    
                    
                    s = s.substring(0,i)+s.substring(i+1);
                }
            }

            if(s.length() > n){
                s = s.substring(0,n);
            }

            System.out.println(s);
        }
        sc.close();
    }
}