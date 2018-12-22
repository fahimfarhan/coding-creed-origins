#include <bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d",&x)
#define sf(x) scanf("%f",&x)

#define pi(x) printf("%d\n",x)
#define pf(x) printf("%.4f\n",x)

#define ll long long int

#define sll(x) scanf("%I64d",&x);
#define pll(x) printf("%-I64d\n",x);

int nCr(int n, int r){
	int nfactByrfact = 1;
	for(int i=r+1; i<=n; i++){
	nfactByrfact  = nfactByrfact*i;
	}

	int n_rfact = 1;
	for(int i=1; i<=n-r; i++){
		n_rfact = n_rfact*i;
	}

	//cout<<nfactByrfact<<"\n";
	//cout<<n_rfact<<"\n";
	//cout<< nfactByrfact/(n_rfact)<<"\n";
	return nfactByrfact/(n_rfact);
}	


int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
  	cout.tie(0);

	
	cout<<"Enter n:\n";

	int n, Cn;
	//n = 3;
	cin>>n;
	int ncr = nCr(2*n,n);
	
	Cn = ncr/(n+1);
	cout<<"Cn = "<<Cn<<"\n";
	/*
	 * Def of Catalan number. WARNING: nCr def too simple. 
	 * Will get error for large num. In practice, copy nCr code from 
	 * DP and then Calculate Catalan number!
	 *
	 * */
	return 0;
}

