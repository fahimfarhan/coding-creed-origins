#include <bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d",&x)
#define sf(x) scanf("%f",&x)

#define pi(x) printf("%d\n",x)
#define pf(x) printf("%.4f\n",x)

#define ll long long int

#define sll(x) scanf("%I64d",&x);
#define pll(x) printf("%-I64d\n",x);

vector<ll> *d;

int main(int argc, char const *argv[])
{
	/* code */
  /* Soln soln */
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

	ll n;

    cin>>n;
    d = new vector<ll>[n+1];
    for(ll i=2; i<=n; i++){
        ll stop = sqrt(i);
        for(int j=i; j<=stop; j+=i){
            d[i].push_back(j);
        }
    }
    ll count = 0;
    while(n!=0){
        n=n-d[n][0];
        count++;
    }

    cout<<count<<"\n";

    if(!d)delete[] d;
	return 0;
}
