#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lb = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        return lb;        
    }
};

int main() {

    Solution s;
    vector<int> v = {1,3,5,6};
    cout<<s.searchInsert(v, 5)<<"\n";
       cout<<s.searchInsert(v, 2)<<"\n";
          cout<<s.searchInsert(v, 7)<<"\n";
             cout<<s.searchInsert(v, 0)<<"\n";
    return 0;
}