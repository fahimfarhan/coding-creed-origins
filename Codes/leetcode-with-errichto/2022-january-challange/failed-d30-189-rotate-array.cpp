#include <bits/stdc++.h>
using namespace std;


class Solution{
	public:
		void rotate(vector<int>& nums, int k) {
			int N = nums.size();
			int mod = k % N;
			if(mod == 0) {
				return;
			}
			int temp = 0;
			int divs = ceil(N / mod);
			for(int i=0; i < mod; i++) {
				temp = nums[i];
				int p = i;
				int q = 0;
				for(int j = 0; j < divs; j++) {
					q += mod;
					if(q >= N) {
						q -= N;
					}
					temp = temp ^ nums[q];
					nums[q] = temp ^ nums[q];
					temp = temp ^ nums[q];
					
					p = q;
				}
			}
		}

		void rotateBruteForceTle(vector<int>& nums, int k) {
			int mod = k % nums.size();

			for(int i=0; i<mod; i++) {
				rotateOnce(nums);
			}
		}

		void rotateOnce(vector<int>& nums) {
			int N = nums.size();
			int j = 0;
			int temp = nums[0];
			for(int i=0; i<N; i++) {
				j = i+1;
				if(j >= N) {	j-= N; }

				temp = temp ^ nums[j];
				nums[j] = temp ^ nums[j];
				temp = temp ^ nums[j];
			}
		}

		void rotateFailed(vector<int>& nums, int k) {
			int N = nums.size();
			int mod = k % N;

			if(mod == 0) {
				return;
			}

			int prev, next, temp;
			for(int i=0; i<mod; i++) {
				// next = i + mod - N => i = next - mod + N => prev = curr - mod + N
				prev = i - mod + N;
				next = i + mod;

				temp = nums[i];
				nums[i] = nums[prev];

				for(int j = (i+mod); j <= prev; j+=mod) {
					temp = temp ^ nums[j];
					nums[j] = temp ^ nums[j];
					temp = temp ^ nums[j];
				}
			}

			// temp = nums[0];
			// for(int i=0; i<N/2; i++) {
			// 	next = i + mod;
			// 	if(next >= N) {
			// 		next -= N;
			// 	}
			
			// 	nums[i] = nums[i] ^ nums[next];
			// 	nums[next] = nums[i] ^ nums[next];
			// 	nums[i] = nums[i] ^ nums[next];
			// }
		}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<int> v = {-1,-100,3,99}; // {1, 2, 3, 4, 5, 6, 7};

	Solution s;
	s.rotate(v, 2);

	for(int i=0; i<v.size(); i++) {
		cout<<v[i]<<" ";
	}cout<<"\n";

	return 0;
}
