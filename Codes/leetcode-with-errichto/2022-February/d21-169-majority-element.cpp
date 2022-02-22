#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
			unordered_map<int, int> mp;
			// int N = nums;
			for(auto num: nums) {
				mp[num]++;
			}
			int key, value = INT_MIN;
			for(auto entry: mp) {
				if(entry.second > value) {
					key = entry.first;
					value = entry.second;
				}
			}
			return key;
    }
};


int main() {
	


	return 0;
}
