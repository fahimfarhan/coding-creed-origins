import java.util.*;


public class Solution {

  public static void main(String[] args) {
    Solution s = new Solution();
    System.out.println(s.champagneTower(1, 1, 1));
  }

  public double champagneTower(int poured, int query_row, int query_glass) {
    double[][] dp = new double[105][105];
    

    dp[0][0] = poured;
    for(int i=0; i<104; i++) {
      for(int j=0; j<=i; j++) {
        if(dp[i][j] > 1) {
          double pouredOut = dp[i][j] - 1;
          dp[i][j] = 1;
          double halfOfPouredOut = pouredOut / 2;
          dp[i+1][j] += halfOfPouredOut;
          dp[i+1][j+1] += halfOfPouredOut;
        }
      }
    }
    
    return  dp[query_row][query_glass];
  }
}