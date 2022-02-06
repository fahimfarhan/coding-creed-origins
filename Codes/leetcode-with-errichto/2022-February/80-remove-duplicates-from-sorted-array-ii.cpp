#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
			int k = 0;

			for(int num: nums) {
				if( (k < 2) || (num > nums[k - 2])) {
					nums[k] = num;
					k++;
				}
			}

			return k;
    }
};


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// 0,0,1,1,1,1,2,3,3
	
	vector<int> input = {0,0,1,1,1,1,2,3,3};
	Solution s;
	cout<<s.removeDuplicates(input)<<"\n";

	// 
	// 
	cout<<"--- output ---\n\n";
	for(auto num: input) {
		cout<<num<<" ";
	}cout<<"\n";
	return 0;
}
