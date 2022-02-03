#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
      unordered_map<int, int> mp;
      int N = nums1.size();
      int a = 0;
      for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
          a = nums1[i] + nums2[j];
          mp[a]++;
        }
      }

      int count = 0;
      for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
          a = -(nums3[i] + nums4[j]);
          if(mp[a]) {
            count+=mp[a];
          }
        }
      }      
      return count;
    }
};

int main() {


  return 0;
}