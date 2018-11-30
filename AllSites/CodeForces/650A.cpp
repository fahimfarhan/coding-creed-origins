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
  int n;
  ll x,y,ans=0;
  map< ll , int > a,b;
  map< pair< ll,ll >, int > c;

  cin>>n;
  for(int i=0; i<n; i++){
    cin>>x>>y;
    pair<ll,ll> p(x,y);
    ans = ans + a[x] + b[y] - c[p];
    a[x]++; b[y]++;  c[p]++;
    
  }
  cout<<ans<<"\n";
	return 0;
}
