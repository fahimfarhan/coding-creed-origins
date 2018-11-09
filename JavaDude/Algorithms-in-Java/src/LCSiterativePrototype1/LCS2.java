package LCSiterativePrototype1;

import static java.lang.Integer.max;

/**
 * Created by Fahim on 11/19/2016.
 */
public class LCS2 {
    final int up = 0;
    final int left = 1;
    final int diag = 2;

    int l1;
    int l2;

    String s1, s2;

    String lcs ;
    int dp[][];
    int dir[][];

    LCS2(String s1, String s2){
        this.s1 =" " + s1;
        this.s2 =" " + s2;
        lcs = "";
        l1 = s1.length();
        l2 = s2.length();
    }

    void F1(){
        dp = new int[50][50];
        dir = new int[50][50];
        for(int i=0;i<=l1;i++) dp[0][i]=0;
        for(int j=0;j<=l2; j++) dp[j][0]=0;


        for(int i=1;i<=l1;i++) {
            for (int j = 1; j <=l2; j++) {
                if (s1.charAt(i) == s2.charAt(j)) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    dir[i][j] = diag;
                } else{

                    if(dp[i - 1][j]>= dp[i][j - 1]){        //dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                        dp[i][j] = dp[i - 1][j];
                        dir[i][j] = left;

                    }
                    else if(dp[i - 1][j]< dp[i][j - 1]){

                        dp[i][j] = dp[i][j-1];
                        dir[i][j] = up;

                    }
                }
            }
        }
            //return dp[s1.length()-1][s2.length()];
    }

    void PrintLCS(){
        int i1 = l1;
        int i2 = l2;
        while(i1>0 || i2 > 0) {

            if(dir[i1][i2] == diag){
                lcs = s1.charAt(i1)+lcs;
                i1--;
                i2--;
            }
            else if(dir[i1][i2] == left)
                i1--;
            else if(dir[i1][i2] == up)
                i2--;
        }

        System.out.println("The length of the LCS is = "+ dp[l1][l2]);
        System.out.println("The LCS is = "+ lcs);
    }

}
