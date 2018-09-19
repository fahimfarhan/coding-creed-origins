#include <bits/stdc++.h>

using namespace std;

int main()
{
	/*
	 * 50! = 3.041x10^64 
	 * => log 50! = log 3.041 + 64 
	 * log(ab) = loga + logb 
	 *
	 *
	 * */
	int n = 50;
	double ans = 0;

	for(int i=1; i<=n; i++){
		ans = ans + log10(i);
	}

	cout<<(int)ans<<"\n";

	return 0;
}
