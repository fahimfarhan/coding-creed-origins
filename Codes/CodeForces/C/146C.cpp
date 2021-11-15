#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string a, b;

	cin>>a;
	cin>>b;

	int n = a.size();

	int count4 = 0;
	int count7 = 0;

	for(int i=0; i<n; i++) {
		if(a[i] != b[i]) {
			if(a[i] == '7') {
				count7++;
			} else {
				count4++;
			}
		}
	}

	int minimus = min(count4, count7);
	int diff = count7-minimus + count4 - minimus;

	int result = minimus + diff;

	cout<<result<<"\n";

	return 0;
}
