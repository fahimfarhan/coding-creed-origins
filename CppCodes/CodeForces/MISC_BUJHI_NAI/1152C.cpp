#include<bits/stdc++.h>
using namespace std;
#define int long long

int a,b,d,ans=1e18+5,k;
void f(int x) {
	int kk = (x-a%x)%x;
	int yo = (a+kk)/x*(b+kk);
	if(ans==yo) k = min(k,kk);
	if(ans>yo) {
		ans = yo;
		k = kk;
	}
}
main() {
	cin>>a>>b;
	d = abs(a-b);
	for(int i=1;i*i<=d;i++) {
		if(d%i==0) {
			f(i); f(d/i);
		}
	}
	cout<<k;
}