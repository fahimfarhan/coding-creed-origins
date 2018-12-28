import java.util.*;

public class Start{
    public static void main(String[] Args){
        Scanner sc = new Scanner(System.in);

        while(sc.hasNextInt()){
            int in = sc.nextInt();
            if(in == 0){    break;  }
            else if(in == 1){  Database db = Database.getInstance(); }
            else{   System.out.println("Try again!");   }
        }
    }
}