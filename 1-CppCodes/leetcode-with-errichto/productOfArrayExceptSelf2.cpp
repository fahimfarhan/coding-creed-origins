#include <bits/stdc++.h>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> output;

    int zeroKount = 0;
    int product = 1;
    for(int i=0; i<n; i++) {
        if(nums[i] == 0) {
            zeroKount++; 
        }else{
            product = product*nums[i];
        }
    }

    if(zeroKount>1) {
        // all zero
        for(int i=0; i<n; i++) {    output.push_back(0);    }
    }else if(zeroKount == 1) {
        for(int i=0; i<n; i++) {    
            if(nums[i] == 0)    output.push_back(product);
            else output.push_back(0);
        }
    }else{
        // for(int i=0; i<n; i++) {
        //     int temp = product/nums[i];
        //     output.push_back(temp);
        // }
        vector<int> outputByDefaultAllZeroes(n); // evabe init korle all zero thake. tai Errichto ei block e kisui kore ni. just hastesilo :/
        return outputByDefaultAllZeroes;         // if you init like this way, by default all elements are zero. So Errichto did nothing in this block and he was smiling :/ 
    }
    return output;
}

int main() {
    vector<int> v = {1,0};
    vector<int> output = productExceptSelf(v);

    for(auto i : output) {
        cout<<i<<" ";
    }
    cout<<"\n";
    return 0;
}