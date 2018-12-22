package Knapsack_0_1_Prototype;

//import static sun.swing.MenuItemLayoutHelper.max;

/**
 * Created by Fahim on 11/25/2016.
 */

public class Knapsack {
    public int [][]dp;
    Knapsack(){}

    int max(int a, int b){ return (a>b)?a:b; }
    int K(int W, int []wt, int []val){

        int n = val.length;
        dp = new int[n+1][W+1];
        /**build a table in bottom up manner*/
        for(int i=0; i<=n; i++){

            for(int j=0; j<= W;j++ ){

                if(i==0 || j==0)
                    dp[i][j] = 0;
                else if(wt[i-1]<=j)
                    dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j] );
                else    dp[i][j] = dp[i-1][j];
            }
        }
        for(int i=0; i<=n; i++){
            for(int j=0; j<=W; j++){
                System.out.print(""+dp[i][j]+" ");
            }
            System.out.println("");
        }
        return dp[n][W];
    }
}
