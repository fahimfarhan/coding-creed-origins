package MCMPrototype2;

/**
 * Created by Fahim on 11/20/2016.
 */
public class MainMCM2 {
    public static void main(String [] args){

        int[] p = new int[]{10, 40, 5, 20, 30,50};
        Functions F = new Functions(p);

        int x = F.M1(1,p.length-1);


        System.out.println(F.explored+" Ans = " + x);
        F.Printer();
    }
}
