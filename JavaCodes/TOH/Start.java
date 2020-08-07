import java.util.*;

public class Start{
    public static void main(String[] Args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        System.out.println("Given number of disks = "+n);
        new Algorithm(n).ai();
        sc.close();
    }
}