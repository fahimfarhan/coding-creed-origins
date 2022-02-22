#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
			vector<int> ret;
			unordered_map<int, int> mp;
			int N = nums.size();
			int limit = N / 3;

			for(auto num: nums) {
				mp[num]++;
			}

			for(auto entry: mp) {
				if(mp.second > limit) {
					ret.push_back(mp.first);
				}
			}
			return ret;
    }
};

int main() {
	return 0;
}
