#include <bits/stdc++.h>

using namespace std;


int main()
{
	/*
	 *
	 * 12300000 = a. a er 5 ta 0 ase. so 10x10x...5ta 10
	 * [n/p]+[n/p^2] + [n/p^3]+...
	 * */

	int n = 100;
	int p = 5;
	int count = 0;
	while(p<n){
		count+=(int)n/p;
		p = p*p;
	}

	cout<<count<<"\n";
	return 0;
}
