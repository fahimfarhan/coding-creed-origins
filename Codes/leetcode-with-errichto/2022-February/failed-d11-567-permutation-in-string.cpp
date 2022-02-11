#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
			unordered_set<char> uset;


			int N = s2.size();
			for(int i=0; i<N; i++) {
				uset.insert(s2[i]);
			}

			N = s1.size();
		
			bool exists = true;

			for(int i=0; i<N; i++) {
				exists = uset.find(s1[i]) != uset.end();

				if(!exists) {
					break;
				}
			}
			return exists;
    }
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s1 = "ab";
	string s2 = "eidbaooo";

	Solution s;
	cout<<s.checkInclusion(s1, s2)<<"\n";
	string s3 = "ab"; string s4 = "eidboaoo";

	cout<<s.checkInclusion(s3, s4)<<"\n";


	return 0;
}
