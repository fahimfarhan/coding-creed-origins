#include <bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d",&x)
#define sf(x) scanf("%f",&x)

#define pi(x) printf("%d\n",x)
#define pf(x) printf("%.4f\n",x)

#define ll long long int

#define sll(x) scanf("%I64d",&x);
#define pll(x) printf("%-I64d\n",x);

int sn2(int n, int k){
	if( (k==1) || (n==k) ){	return 1; }
	return sn2(n-1, k-1) + k*sn2(n-1, k);
}


int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
  	cout.tie(0);

	int n, k;
	n = 5, k = 3;
	cout<<sn2(n,k)<<"\n";
	return 0;
}

