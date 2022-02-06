#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int sameCount = 0;
			 int k = 0;
			 int N = nums.size();
			 // int prevValue = nums[0];
			 for(int i=0; i<N; i++) {
					if( (nums[k] == nums[i]) && (sameCount < 2) ) {
						nums[k] = nums[i];
						k++;
						sameCount++;
						// prevValue = nums[k];
					} else if(nums[k]!=nums[i]){
						k++;
						nums[k] = nums[i];
						sameCount = 0;
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
