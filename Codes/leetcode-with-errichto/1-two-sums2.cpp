#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int N = nums.size();
        map<int, vector<int> > mp;
        vector<int> result;
        for(int i=0; i<N; i++) {
          mp[nums[i]].push_back(i);
        }


        int isFound = false;
        for(int i=0; i<N; i++) {
          if(isFound) { break;  }
          int a = nums[i];
          int b = target - a;
          if(mp[b].size() > 0) {
            for(int k=0; k<mp[b].size(); k++) {
              int k1 = mp[b][k];
              if(k1 != i) {
                int j = k1;
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
  vector<int> input;
  input.push_back(3);
  input.push_back(2);
  input.push_back(4);

  Solution sol;
  vector<int> output = sol.twoSum(input, 6);
  for(int i=0; i<output.size(); i++) {
    cout<<output[i]<<" ";
  }cout<<"\n";
  return 0;
}