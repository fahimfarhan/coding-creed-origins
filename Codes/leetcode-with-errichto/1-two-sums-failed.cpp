#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int N = nums.size();
        int *cf;
        cf = new int[N+1];  
        // nums is 0 based indexing
        // cf array is 1 based indexing for convenience
        cf[0] = 0;
        for(int i=1; i<=N; i++) {
          cf[i] = cf[i-1]+nums[i-1];
          // cf[i] = cf[i-1]+nums[i];  u would use this if nums was in 1 based indexing
        }

        vector<int> result;
        int currentSum = 0;
        // bool isResultFound = false;      
        for(int i=1; i<=N; i++) {
          // if(isResultFound) { break;  }
          for(int j=i; j<=N; j++) {
            if( (cf[j] - cf[i-1]) >= target) {
              // ans is (i-1), (j-1)  , -1 to convert 1 based indexing to 0 based indexing
              if( (cf[j] - cf[i-1]) < currentSum) {
                result.clear();
                result.push_back((i-1));
                result.push_back((j-1));
                currentSum = (cf[j] - cf[i-1]);
              }
              // isResultFound = true;
              break;
            }
          }
        }

        delete[] cf;
        return result;
        
    }
};

int main() {


  return 0;
}