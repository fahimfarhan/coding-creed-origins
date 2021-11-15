#include <bits/stdc++.h>
using namespace std;

inline bool isLuckyNumber(const int& n, const string& s) {
	// bool isLucky = true;
	for(int i=0; i<n; i++) {
		if( (s[i] != '4') && (s[i] != '7') ) {
			return false;
		} 
	}
	return true;
}

inline int calculatePrefixSum(const int& n, const string& s) {
	int m = n/2;
	int sum = 0;
	for(int i=0; i<m; i++) {
		sum += (s[i] - '0');
	}
	return sum;
}

inline int calculateSuffixSum(const int& n, const string& s) {
	int m = n/2;
	int sum = 0;
	for(int i=m; i<n; i++) {
		sum += (s[i] - '0');
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	string s;
	
	

	cin>>n;
	cin>>s;

	// cout<<isLuckyNumber(n, s)<<"\n";

	bool isLucky = isLuckyNumber(n, s);

	int prefixSum = calculatePrefixSum(n, s);
	int suffixSum = calculateSuffixSum(n, s);
	
	if ( isLucky && ( prefixSum == suffixSum ) ) {
		cout<<"YES\n";
	} else {
		cout<<"NO\n";
	}	
	return 0;
}
