#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool ret = true;
        int n = nums.size();
        int maximus = 0;
        
        for(int i=0; i<n; i++) {
            maximus = max(nums[i], (maximus-1) );
            if(maximus == 0 && i != (n-1) ) {
                ret = false;
                break;
            }
        }
        return ret;
    }
};

int main() {


    return 0;
}