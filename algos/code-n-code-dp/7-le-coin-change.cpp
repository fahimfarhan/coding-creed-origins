#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  const int INF = 100000000;

  vector<int> dp;

  void preProcess(vector<int>& coins, const int& amount) {
    dp.resize(100005);
    for(int i=0; i<dp.size(); i++) {
      dp[i] = INF;
    }

    dp[0] = 0;
    for(int coin: coins) {
      dp[coin] = 1;
    }
  }

  int getDp(vector<int>& coins, int someAmount) {
    if(someAmount < 0 || someAmount >= dp.size()) {
      return INF;
    }

    if(dp[someAmount] != INF) {
      return dp[someAmount];
    }

    for(int coin: coins) {
      if(coin <= someAmount) {
        dp[someAmount] = min(dp[someAmount],  1 + getDp(coins, (someAmount - coin)) );
      }
    }
    return dp[someAmount];
  }

  int coinChange(vector<int>& coins, int amount) {
    preProcess(coins, amount);
    int ret = getDp(coins, amount);
    if(ret == INF) {
      ret = -1;
    }
    return ret;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  Solution s;

  return 0;
}