#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int case1 = maxProfitCase1(prices);
        int case2 = maxProfitCase2(prices);

        return max(case1, case2);
    }

    int maxProfitCase1(vector<int>& prices) {
      int extrema = 100000+5;
        int N = prices.size();

        int minimaPos = 0;
        int maximaPos = 0;
        for(int i=0; i<N; i++) {
          if(prices[i] < extrema) {
            minimaPos = i;
            extrema = min(extrema, prices[i]);
          }
        }

        // extrema = prices[minimaPos];
        maximaPos = minimaPos;
        for(int i=minimaPos; i<N; i++) {
          if(prices[i] > extrema) {
            maximaPos = i;
            extrema = prices[i];
          }
        }

        return prices[maximaPos] - prices[minimaPos];
    }

    int maxProfitCase2(vector<int>& prices) {
      int extrema = -100000-5;
      int N = prices.size();

        int minimaPos = 0;
        int maximaPos = 0;
        for(int i=0; i<N; i++) {
          if(prices[i] > extrema) {
            maximaPos = i;
            extrema = prices[i];
          }
        }

        minimaPos = maximaPos;
        for(int i=maximaPos; i >=0; i--) {
          if(prices[i] < extrema) {
            minimaPos = i;
            extrema = prices[i];
          }
        }
      
        return prices[maximaPos] - prices[minimaPos];
    }
};

int main() {
  Solution s;
  vector<int> v = {2, 4, 1};
  cout<<s.maxProfit(v)<<"\n";

  return 0;
}