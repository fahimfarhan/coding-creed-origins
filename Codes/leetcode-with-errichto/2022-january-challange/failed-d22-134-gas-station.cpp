#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int returnIndex = 0;
        int start = -1;
        int N = gas.size();

        for(int i=0; i<N; i++) {
          bool canComplete = canCarComplete(i, gas, cost);
          cerr<<"canComplete = "<<canComplete<<"\n";
          if(canComplete) {
            start = i + 1;
            break;
          }
        }
        return start;
    }

private:
  bool canCarComplete(int start, vector<int>& gas, vector<int>& cost) {
    int N = gas.size();
    int tank = 0;
    int j = start;
    bool canComplete = true;
    int failedIndex = -1;
    for(int i=0; i<N; i++) {
      j += 1;
      if(j == N) {
        j = 0;
      }

      tank += gas[j] - cost[j];
      if(tank < 0) {
        canComplete = false;
        failedIndex = j;
        break;
      }
    }
    return canComplete;
  }
};

int main() {
  Solution s;
  vector<int> gas = {3, 1, 1}; // {2,3,4}; // {1,2,3,4,5};
  vector<int> cost = {1, 2, 2}; // {3,4,3}; // {3,4,5,1,2};
  int ans = s.canCompleteCircuit(gas, cost);
  cout<<ans<<"\n";

  return 0;
}