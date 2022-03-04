#include <bits/stdc++.h>
using namespace std;

class Solution {
      double dp[105][105] = {0};
public:
    void printer() {
      for(int i=0; i<105; i++) {
        for(int j=0; j<105; j++) {
          cout<<dp[i][j]<<" "; // = 0.0;
        } cout<<"\n";
      }
    }

    double champagneTower(int poured, int query_row, int query_glass) {
      dp[0][0] = poured;
      
      for(int i=0; i<101; i++) {
        for(int j=0; j<=i; j++) {
          if(dp[i][j] > 1) {
            double pouredOut = dp[i][j] - 1.0;
            dp[i][j] = 1;
            double halfOfPouredOut = pouredOut / 2;
            dp[i+1][j] += halfOfPouredOut;
            dp[i+1][j+1] += halfOfPouredOut;
          } 
          //else {
            // pouredOut = 0;
          //}
        }
      }
      return dp[query_row][query_glass];
    }
};

int main() {
  Solution s;
  cout<<s.champagneTower(100000009, 33, 17)<<"\n";
  s.printer();
  return 0;
}