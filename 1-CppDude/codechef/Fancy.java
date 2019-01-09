import java.util.*;

public class Fancy{
    public static void main(String[] Args){
        int T;
        Scanner sc = new Scanner(System.in);
        
        T = sc.nextInt();
        String s = "";
        boolean b = false;
        while(sc.hasNextLine()){
            s = sc.nextLine();
            T--;
            //System.out.println(T+" " + s);
            String[] a = s.split(" ");
            //System.out.println("size = "+a.length);
            if(a.length != 1){
                b = false;
                for(int i=0; i<a.length; i++){
                    if(a[i].equals("not")){
                        b = true; break; 
                    }
                }
                if(b){  System.out.println("Real Fancy");   }
                else{   System.out.println("regularly fancy"); }
            }
            
        }
        sc.close();
    }
}