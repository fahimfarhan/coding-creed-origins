package MCMPrototype;

/**
 * Created by Fahim on 11/19/2016.
 */
public class MCM1 {

    int [] p; //p=p0,p1, p2...
    int [][] dp;
    int [][] s;
    int[][] div;
    final int inf = 99999;
    int len;

    MCM1(int []p){

        this.p = p;
        len = p.length;
        dp = new int[len][len];
        s = new int[len][len];
       // div = new int[len][len];
        for(int i=0; i<len; i++)
            for(int j=0; j<len;j++)
                dp[i][j] = inf;
        for(int i=1;i<len; i++)  dp[i][i]= 0;

        for(int l=2; l<len; l++)
            for(int i=1; i<len-l+1; i++){

                int j=i+l-1;
                for(int k=i;k<j;k++){

                    int temp = dp[i][k] + dp[k+1][j] + p[i-1]*p[k]*p[j];
                    if(temp< dp[i][j]){
                        dp[i][j] = temp;
                        s[i][j] = k; // div[i][j] = k ;
                    }
                }
            }
    }
    void printTables(){
        System.out.println("\n\ndp[][]");
        for(int i=0; i<len;i++){
            for(int j=0;j<len; j++){

                System.out.print(""+dp[i][j]+" ");
            }
            System.out.println("");
        }
        System.out.println("\ns[][]");
        for(int i=0; i<len;i++){
            for(int j=0;j<len; j++){

                System.out.print(""+s[i][j]+" ");
            }
            System.out.println("");
        }
    }
    void PrintMCM(int i, int j){    //print(dp[][], i, j)
        if(i==j)
            System.out.print("A"+i);
        else{
            System.out.print("(");
            PrintMCM(i, s[i][j]);
            PrintMCM(s[i][j]+1,j);
            System.out.print(")");
        }

    }
}
