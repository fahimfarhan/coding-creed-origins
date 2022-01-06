#include <bits/stdc++.h>
using namespace std;

#define ll long long int
class Solution {
public:
  static const int M = 1000+1;
  bool carPooling(vector<vector<int>>& trips, int capacity) {
      int dp[M] = {0};
      int a[M] = {0};
      bool isPossible = true;
      int numPassangers, from, to;
      int maximus = 0;
      for(auto trip: trips) {
        numPassangers = trip[0];
        from = trip[1];
        to = trip[2];

        maximus = max(to, maximus);

        a[from] += numPassangers;
        a[to] -= numPassangers;
      }

      dp[0] = a[0];
      
      for(int i=1; i<M; i++) {
        dp[i] = dp[i-1] + a[i];
      }


      for(int i=0; i<= maximus; i++) {
        if(dp[i] > capacity) {
          isPossible = false;
          break;
        }
      }

      return isPossible;
  }
};

int main() {
  Solution s;
  vector<vector<int>> case1{ {2,1,5}, {3,3,7} };
  vector<vector<int>> case2{ {2,1,5}, {3,3,7} };

  cout<<s.carPooling(case1, 4)<<"\n";
  cout<<s.carPooling(case2, 5)<<"\n";

  return 0;
}