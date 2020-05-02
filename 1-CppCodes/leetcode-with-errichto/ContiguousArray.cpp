#include <bits/stdc++.h>

using namespace std;

/**
 *  @brief idea credit: errichto. Use prefixSum/cummulativeFrequency 
 *      cf(R,L) = cf[R] - cf[L-1];
 */
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size(), result = 0;
        for(int i=0; i<n; i++) {    if(nums[i] == 0) nums[i] = -1; } 
        
        vector<int> cf;
        cf.push_back(0);

        for(int x : nums) { cf.push_back( (cf.back() + x) ); } 

        unordered_map<int,int> firstOccurance;
        for(int i=0; i<cf.size(); i++ ) {
            int x = cf[i];
            auto it = firstOccurance.find(x);
            if(it != firstOccurance.end()) {
                result = max(result, (i - firstOccurance[x]) );
            }else{
                firstOccurance[x] = i;
            }
        }
        return result;
    }
};

int main() {
    vector<int> v = {0,1,1,0,1,1,1,0}; // 
    Solution s;
    cout<<s.findMaxLength(v)<<"\n";
    
    return 0;
}