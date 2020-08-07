#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> cf;
        cf.push_back(0);
        for(int i=0; i<nums.size(); i++) {
            int x = cf[i] + nums[i];
            cf.push_back(x);
        }      

        int n = nums.size();
        
        int kount = 0;
        
        for(int l = 1; l <=n; l++) {
            for(int r=l; r<=n; r++) {
                if(cf[r]-cf[l-1] == k) {
                    kount++;
                }
            }
        }

        return kount;
    }
};

int main() {


    return 0;
}