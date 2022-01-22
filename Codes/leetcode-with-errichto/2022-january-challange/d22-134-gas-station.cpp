#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      int start = -1;
      int N = gas.size();
      int capacity = 0;

      for(int i=0; i<N; i++) {
        capacity += (gas[i] - cost[i]);

        if(capacity < 0) {
          start = -1;
          capacity = 0;
        } else if(start == -1) {
          start = i;
        }
      }

      if(start != -1) {
        for(int i=0; i<start; i++) {
          capacity += (gas[i] - cost[i]);
          if(capacity < 0) {
            start = -1;
            break;
          }
        }        
      }
      return start;
    }
};

int main() {
  Solution s;
  vector<int> gas = //{2,3,4}; // 
  {1,2,3,4,5};
  vector<int> cost = //{3,4,3}; // 
  {3,4,5,1,2};
  int ans = s.canCompleteCircuit(gas, cost);
  cout<<ans<<"\n";

  return 0;
}