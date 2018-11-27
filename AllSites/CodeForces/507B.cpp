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

	ll r, x,y, a,b; double d;
    cin>>r>>x>>y>>a>>b;
    d = (x-a)*(x-a)+(y-b)*(y-b);
    d = sqrt(d);
    //cout<<d<<"\n";
    ll ans = d/(2*r);
    double myremainder = d - ans*2*r;

    //cout<<ans<<" "<<myremainder<<"\n";
    if( myremainder!=0){ans++;}
    cout<<ans<<"\n";
	return 0;
}
