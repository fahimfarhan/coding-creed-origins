#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
      int cointSize = coins.size();
      int dp[amount + 1];
      dp[0] = 0;

      int inf = 100000000;

      for(int i = 1; i <= amount; i++) {
        dp[i] = inf;
      }        

      for(int i = 1; i <= amount; i++) {
        int ans = inf;
        for(int j = 0; j < cointSize; j++) {
          if(coins[j] <= i) {
            ans = min(ans, dp[i - coins[j]]);
          }
        }

        if(ans == inf) {  dp[i] = -1; }
        else {  dp[i] = ans + 1;  }
      }
      if(dp[amount] == inf) { return -1;  }
      
      return dp[amount];  
    }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  Solution s;

  return 0;
}