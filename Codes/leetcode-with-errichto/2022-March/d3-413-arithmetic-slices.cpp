#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
      int N = nums.size();
      if(N < 3) {
        return 0;
      }
      
      int start = 0, end = 0;
      vector<pair<int, int>> v;

      int diff = nums[1] - nums[0];
      int tempDiff = 0;
      
      // step1: Find all contiguous subLists with same differences
      for(int i=2; i<N; i++) {
        tempDiff = nums[i] - nums[i-1];
        
        if(tempDiff!=diff) {
          end = i-1;
          v.push_back({start, end});
          start = end;
          diff = tempDiff;
        }
      }

      v.push_back({start, N-1});

      // step2: apply the fotmula
      int count = 0;
      for(auto p: v) {
        N = p.second - p.first + 1; 
        count += ((N+1)*(N-2) - N*(N+1)/2 + 3);
      }
      return count;
    }
};

int main() {

  return 0;
}