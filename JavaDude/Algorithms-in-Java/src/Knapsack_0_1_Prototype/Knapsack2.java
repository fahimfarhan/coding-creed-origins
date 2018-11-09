package Knapsack_0_1_Prototype;

/**
 * Created by Fahim on 11/25/2016.
 */
public class Knapsack2 {
    int dp[][];
    int len;
    int W;
    int wt[], val[];
    Knapsack2(int W, int len){
        dp = new int[len+1][W+1];
        for(int i=0; i<=len; i++)
            for(int j=0; j<=len; j++)
                dp[i][j] = -1;
        this.len = len;
        this.W = W;
    }
    int max(int a, int b){ return (a>b)?a:b; }
    int rk(int W, int[] wt, int[] val, int n){
        if(n==0 || W==0)
            return dp[n][W]=0;
        if(wt[n-1]>W)
            return dp[n][W] = rk(W, wt, val, n-1);
        else
            return dp[n][W] = max(val[n-1]+ rk(W-wt[n-1],wt, val, n-1 ), rk(W, wt, val, n-1));
    }

    void printer(){
        //for(int j=0; j<=len; j++)
            System.out.println("\nrecursive table: ");

        for(int i=0; i<=len; i++){
            for(int j=0; j<=W; j++){
                System.out.print(""+dp[i][j]+" ");
            }
            System.out.println("");
        }
    }
}
