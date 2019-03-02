package Knapsack_0_1_Prototype;

/**
 * Created by Fahim on 11/25/2016.
 */
public class MainK {

    public static void main(String [] args) throws Exception{

        Knapsack K = new Knapsack();

        int[] val = new int[]{7, 4, 15, 5};
        int[] wt = new int[]{3, 2, 1, 4};
        int W = 8;
        int n = K.K(W, wt, val);
        System.out.println("Ans = "+n);

        /**test 2: recursive way*/
        //try{

        Knapsack2 k = new Knapsack2(W, wt.length);
        int x = k.rk(W,wt, val, wt.length);
        k.printer();
        System.out.println("Ans (recursive way)= "+x);

        //}catch(Exception x){System.out.println(x);}
    }
}
