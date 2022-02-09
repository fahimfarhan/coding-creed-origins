#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

int findPairsithNonZeroK(vector<int>& nums, int k) {
int pairCount = 0;
      unordered_set<int> uset;
      for(auto num: nums) {
        uset.insert(num);
      }

      int m = 0;
      bool exists = false;
      
      /**
      for(auto num: nums) {
        m = num + k;
        exists = uset.find(m) != uset.end();
        if(exists) {
          pairCount++;
          // it could be counted twice, we should remove these 2 numbers from the set to avoid repeats.
          // that could cause errors. let's iterate over the items of the set, not the vector
          cout<<"( "<<num<<" , "<<m<<" )\n";
        }
      }
      */

      for(auto num: uset) {
        m = num + k;
        exists = uset.find(m) != uset.end();
        if(exists) {
          pairCount++;
          cerr<<"( "<<num<<" , "<<m<<" )\n";
        }
      }

      return pairCount;
}

int findPairsithZeroK(vector<int>& nums) {
  int pairCount = 0;
  unordered_map<int, int> mp;
  for(auto num: nums) {
    mp[num]++;
  }

  for(auto num: nums) {
    if(mp[num] > 1) {
      pairCount++;
      mp[num] = 0; // else the same pair will be counted multiple times!
    }
  }

  return pairCount;
}



int findPairs(vector<int>& nums, int k) {
  if(k == 0) {
    return findPairsithZeroK(nums);
  } 
  return findPairsithNonZeroK(nums, k);
}

    int findPairsV1(vector<int>& nums, int k) {
      int pairCount = 0;

      unordered_map<int, int> mp;
      for(auto num: nums) {
        if(!mp[num]) {
          mp[num]++;
        }
      }


      int key1, key2, val1, val2;
      for(auto num: nums) {
        key1 = num + k;
        // key2 = num - k;

        val1 = mp[key1];
        // val2 = mp[key2];

        if(val1) {
          pairCount += val1;
        }

        /*
        if(val2) {
          pairCount += val2;
        }
        */
      }

      // let [3, ... ... 1, ...], for loop calcs 3-1=k, 3-1=-k, 1-3=k, 1-3=-k, ie, 
      // each element is added twice. hence divide by 2
      /** pairCount /= 2; */

      // alternatively, comment out key2, val2 part. then you don't need to divide by 2.


      return pairCount;      
    }
};

int main() {
  Solution s;
  vector<int> input = {3,1,4,1,5};
  
  cout<<s.findPairs(input, 2)<<"\n-------------------\n";

  vector<int> in2 = {1,2,3,4,5};
  cout<<s.findPairs(in2, 1)<<"\n-------------------\n";

  vector<int> in3 = {1,3,1,5,4};
  cout<<s.findPairs(in3, 0)<<"\n-------------------\n";

  return 0;
}