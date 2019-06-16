#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,x;
	cin >> n >> x;
	int a[n],sum = 0;
	for (int i=0;i<n;i++) cin >> a[i], sum += a[i];
	cout << ceil(double(abs(sum))/x) << endl;
}