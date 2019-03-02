package Knapsack;

import static java.lang.Integer.max;

/**
 * Created by Tarik on 11/20/2016.
 */
public class Knapsack {
    static int p[];
    static int w[];


    static int k(int i, int cap){
        if(i<0) return 0;

        int p1=0, p2=0;
        if(cap>=w[i]) p1 = p[i]+k(i-1,cap-w[i]);
        p2 = k(i-1,cap);

        return max(p1,p2);
    }



    public static void main(String args[]){

        p = new int[]{10,52,25,5};
        w = new int[]{5,20,10,2};

        System.out.println(""+k(3,36));

    }
}
