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

      char ch;
      int m = 0;
      for(int i=0; i<N; i++) {
        ch = columnTitle[i];
        m = ch - 'A' + 1;
        num = num*26 + m;
      }

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
