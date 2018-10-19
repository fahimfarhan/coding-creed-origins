#include <bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d",&x)
#define sf(x) scanf("%f",&x)

#define pi(x) printf("%d\n",x)
#define pf(x) printf("%.4f\n",x)

#define ll long long int

#define sll(x) scanf("%I64d",&x);
#define pll(x) printf("%-I64d\n",x);

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
    //cin>>n;
    for(int j=1; j<20; j++){
        n=j;
        ll m = (ll)sqrt(n);
        ll count = 0;
        for(int i=1; i<=m; i++){
            count+=(n/i-i+1);
        }
        cout<<j<<"-->"<<count<<"\n";
        
    }
    return 0;
}
