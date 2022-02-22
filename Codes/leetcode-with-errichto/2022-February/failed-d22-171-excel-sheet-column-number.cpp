#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
		int charToNum(char ch) {
			return ch - 'A';
		}

    int titleToNumber(string columnTitle) {
  		int N = columnTitle.size();
			int num = 0;
			
			int exp = 0;
			
			for(int i=N-1; i>=0; i--) {
				exp = (N - 1) - i;
				int temp = pow(26, exp);
				int temp2 = charToNum(columnTitle[i]);


				// cerr<<"temp "<<temp<<"\n";
				num += temp2 * temp;	
			}
			num += 1;

			return num;
    }
};

int main() {
	Solution s;
	cout<<s.titleToNumber("A")<<"\n";
	cout<<s.titleToNumber("B")<<"\n";

	cout<<s.titleToNumber("AB")<<"\n";
	cout<<s.titleToNumber("ZY")<<"\n";

	return 0;
}
