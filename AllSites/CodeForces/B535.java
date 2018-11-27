import java.util.*;
public class B535{
    public static void main(String[] Args){
        Scanner sc = new Scanner(System.in);
        String s;
        int n, pos, l;
        n=0; pos = 0;
        s = sc.next();
        l = s.length();
        pos = (1<<l) - 1;
        for(int i=0; i<l; i++){
            n = n<<1;
            if(s.charAt(i) == '7' ){
                n = n|1;
            }
        }

        pos = pos+n;
        System.out.println(pos);
        sc.close();
    }
}