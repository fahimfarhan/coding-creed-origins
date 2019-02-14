/**
 * Created by Tarik on 11/17/2016.
 */
public class MCM {

    static int p[];

    static int dp[][];

    static int div[][];
    static final int inf = (int) 1e9;

    static int matrixChainOrder(){
        for(int i=0; i < 5; i++){
            for(int j=0; j < 5; j++){
                dp[i][j]= MCM.inf;
            }
        }
        for(int i=0; i < 5; i++){
            dp[i][i]=0;
        }

        for(int l=2; l<=4; l++){
            for(int i=1; i<=4-l+1; i++){
                int j = i+l-1;
                for(int k=i; k<=j; k++){
                    int cost = dp[i][k]+dp[k+1][j]+p[i-1]*p[k]*p[j];
                    if(cost < dp[i][j]){
                        dp[i][j]=cost;
                        div[i][j]=k;
                    }
                }
            }
        }
        return dp[1][4];
    }

    public static void main(String args[]){
        p  = new int[]{10,40,5,20,30};
        dp = new int[10][10];
        div = new int[5][5];
        System.out.println(""+matrixChainOrder());

        for(int i=0;i<=4 ;i++){
            for(int j=0; j<=4; j++){
                System.out.print(""+div[i][j]+" ");
            }
            System.out.println("");
        }
    }
}
