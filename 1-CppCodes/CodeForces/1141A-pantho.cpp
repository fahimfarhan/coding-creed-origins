#include <bits/stdc++.h>
using namespace std;
#define OFF 10005
long long MOD = 1e9+7;
long long dp[1005][3*OFF];
int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	if(m%n!= 0) {
		cout<<"-1";
		return 0;
	}
	int div = m/n;
	int c1 = 0;
	while(div%2 == 0){
		div = div/2;
		c1++;
	}
	int c2 = 0;
	while(div%3 == 0){
		div = div/3;
		c2++;
	}
	if(div != 1){
		cout<<"-1";
		return 0;
	}
	cout<<c1+c2;
	return 0;
}