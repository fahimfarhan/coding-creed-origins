#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int N = nums.size();
        vector<int> result;
        bool isFound = false;
        for(int i=0; i<N; i++) {
          if(isFound) { break;  }
          for(int j=0; j<N; j++) {
            if(i != j) {
              if(nums[i] + nums[j] == target) {
                result.push_back(i);
                result.push_back(j);
                isFound = true;
                break;
              }
            }
          }
        }
        return result;
    }
};

int main() {


  return 0;
}