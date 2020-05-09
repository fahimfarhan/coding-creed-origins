#include <bits/stdc++.h>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    
    vector<int> prefixProduct(n+2);
    vector<int> suffixProduct(n+2);
    vector<int> output;

    prefixProduct[0] = 1;
    suffixProduct[n+1] = 1;
    for(int i=0; i<n; i++) {
        prefixProduct[i+1] = prefixProduct[i] * nums[i];
    }

    for(int i=n; i>=1; i--) {
        suffixProduct[i] = suffixProduct[i+1] * nums[i-1];
    }

    int m = 1;
    for(int i=1; i<=n; i++) {
        m = prefixProduct[i-1]*suffixProduct[i+1]; 
        output.push_back(m);
    }
    return output;
}

int main() {
    vector<int> v = {1,2,3,4};
    vector<int> output = productExceptSelf(v);

    for(auto i : output) {
        cout<<i<<" ";
    }
    cout<<"\n";
    return 0;
}