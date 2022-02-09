#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
			int result = num;

			while(result >= 10) {
				result = sum(result);
			}
			return result;
    }

		int sum(int& input) {
			int a = 0;
			//int input = n;
			int remainder = 0;

			while(input) {
				remainder = input % 10;
				input = input / 10;

				a += remainder;
			}
			return a;
		}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Solution s;
	cout<<s.addDigits(38)<<"\n";
	cout<<s.addDigits(0)<<"\n";
	cout<<s.addDigits(10)<<"\n";

	return 0;
}
