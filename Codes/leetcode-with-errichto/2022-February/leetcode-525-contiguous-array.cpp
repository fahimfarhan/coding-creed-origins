#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
      int result = 0;
      int N = nums.size();
      for(int i=0; i<N; i++) {
        if(nums[i] == 0) {
          nums[i] = -1;
        }
      }

      vector<int> cf;
      cf.push_back(0);

      unordered_map<int, int> mp;
      for(int i=0; i<N; i++) {
        int temp = nums[i] + cf[cf.size() - 1];
        cf.push_back(temp);
      }


      N = cf.size();
      for(int i = 0; i<N; i++) {
        int temp = cf[i];

        bool exists = mp.find(temp) != mp.end();
        if(exists) {
          int start = mp[temp];
          int endPlusOne = i; // since one based indexing I guess...
          result = max(result, endPlusOne - start);
        } else {
          mp[temp] = i;
        }
      }

      return result;
    }
};

int main() {
  Solution s;

  vector<int> test1 = {0, 1};
  vector<int> test2 = {0, 1, 0}; // failed!
  vector<int> test3 = {0, 1, 1, 1, 0, 0, 1, 0, 0, 1};

  cout<<s.findMaxLength(test1)<<"\n";
  cout<<s.findMaxLength(test2)<<"\n";
  cout<<s.findMaxLength(test3)<<"\n";
  return 0;
}