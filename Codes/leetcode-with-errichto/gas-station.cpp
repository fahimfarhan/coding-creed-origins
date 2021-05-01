#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuitFailed(vector<int>& gas, vector<int>& cost) {
      int n = gas.size();
      vector<int> delta; 

      int dx = 0;
      int index = -1;
      for(int i=0; i<n; i++) {
        dx = gas[i] - cost[i];
        delta.push_back(dx);
        if( (dx > 0) && (index != -1)) {
          index = i;
        }
      }     

      bool isPossible = true;
      int sum = 0;
      for(int i=0; i<n; i++) {
        sum+=delta[i];
        if(sum < 0) {
          isPossible = false; break;
        }
      }

      if(!isPossible) { return -1;  }
      sum = 0;
      for(int i=(n-1);  i>=0; i--) {
        sum+=delta[i];
        if(sum < 0) {
          isPossible = false; break;
        }
      }

      if(!isPossible) { return -1;  }
      return index;
    }

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      int N = gas.size();
      int start = -1;
      int capacity = 0;


      for(int i=0; i<N; i++) {
        capacity += gas[i] - cost[i];
        if(capacity < 0) {
          start = -1;
          capacity = 0;
        } else if(start == -1) {
          start = i;
        }
      }

      if(start == -1) { return -1;  }

      for(int i=0; i<start; i++) {
        capacity += gas[i] - cost[i];
        if(capacity < 0) {
         return -1;
        }
      }
      return start;
    }
};

int main() {


  return 0;
}