package MCMPrototype;

/**
 * Created by Fahim on 11/19/2016.
 */
public class MainMCM {
    public static void main(String [] args){
       int []p = {30, 35, 15, 5, 10, 20, 25};
        MCM1 mcm = new MCM1(p);
        System.out.println(mcm.dp[1][p.length-1]);
        mcm.PrintMCM(1,6);
        mcm.printTables();
    }
}
