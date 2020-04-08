#include <bits/stdc++.h>
using namespace std;

int maxSubArrayBruteForce(vector<int>& nums) {
    int n = nums.size();
    int prefSum[n+1];
    prefSum[0] = nums[0];
    for(int i=1; i<n; i++){
        prefSum[i] = prefSum[i-1]+nums[i];
    }

    int ans = 0;
    for(int i=1; i<n; i++){
        for(int j=i; j<n; j++){
            ans = prefSum[j] - prefSum[i-1];
        }
    }
}

int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> cf(n);

    cf[0] = nums[0];
    for(int i=1; i<n; i++) {    cf[i] = cf[i-1]+nums[i];    }

    int min_so_far = 0;
    int ans = INT_MIN;

    for(int i=0; i<n; i++) {
        ans = max(ans, cf[i] - min_so_far);
        min_so_far = min(min_so_far, cf[i]);
    }
    return ans;
}

int main(){

    return 0;
}