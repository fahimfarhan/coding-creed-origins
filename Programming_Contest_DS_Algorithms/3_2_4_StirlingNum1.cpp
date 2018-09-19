#include <bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d",&x)
#define sf(x) scanf("%f",&x)

#define pi(x) printf("%d\n",x)
#define pf(x) printf("%.4f\n",x)

#define ll long long int

#define sll(x) scanf("%I64d",&x);
#define pll(x) printf("%-I64d\n",x);

int sn1(int n, int k){
	if( (n==k) ){	return 1; 	}
	if(k == 1) 
	{
		int ret = 1;
		for(int i=1; i<=n-1; i++){	ret = ret*i;	}
		return ret;
	}
	
	return sn1(n-1, k-1) + (n-1)*sn1(n-1, k);
}


int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
  	cout.tie(0);

	int n, k;
	n = 5, k = 3;
	cout<<sn1(n,k)<<"\n";
	return 0;
}

