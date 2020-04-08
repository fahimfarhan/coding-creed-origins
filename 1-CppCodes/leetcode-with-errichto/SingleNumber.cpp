#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for(int i=0; i<nums.size(); i++){
            ret = ret^nums[i];
        }
        return ret;
    }
};

int main(){

    return 0;
}