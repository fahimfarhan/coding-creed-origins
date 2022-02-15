#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
			int singleNum = 0;
			int N = nums.size();
			for(int i=0; i<N ; i++) {
				singleNum ^= nums[i];
			}
			return singleNum;
    }
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	vector<int> v = {2, 2, 1};
	Solution s;
	cout<<s.singleNumber(v)<<"\n";

	return 0;
}
