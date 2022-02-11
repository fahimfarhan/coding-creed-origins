#include <bits/stdc++.h>
using namespace std;

#define TRUE -1
#define FALSE -2

class Solution {
public:

	int charFreq[26] = {0};	

	bool checkInclusion(const string& s1, const string& s2) {
		int N = s1.size();
		int k = 0;
	
		// step1: init char frequency
		for(int i=0; i<N; i++) {
			k = s1[i] - 'a';
			charFreq[k]++;
		}

		int p1 = 0;
		N = s2.size();
		while(p1 < N) {
			k = s2[p1] - 'a';

			if(charFreq[k]) {
				// check using pointer2
				int result = slidingWindow(s1, s2, p1);
				if(result == TRUE) {
					return true;
				} else if(result == FALSE) {
					p1++;
				} else {
					if(result <= p1) {
						p1+=1;
					}else {
						p1 = result;
					}
				}
			} else {
				p1++;
			}
		}

		return false;
  }

	int slidingWindow(const string& s1, const string& s2, const int& start) {
		int temp[26] = {0};
		int end = start + s1.size();
		int N = s2.size();

		if(end > N) {
			return false;
		}

		char ch = '\0';
		int k = 0;
		for(int p2 = start; p2 < end; p2++) {
			ch = s2[p2];
			k = ch - 'a';
			
			if(!charFreq[k]) {
				return p2;
			} else {
				temp[k]++;
			}
		}
		
		for(int i=0; i<26; i++) {
			if(charFreq[i] != temp[i]) {
				return FALSE;
			}
		}
		return TRUE;
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
	string s5 = "hello";
	string s6 = "ooolleoooleh";

	cout<<s.checkInclusion(s5, s6)<<"\n";

	return 0;
}
