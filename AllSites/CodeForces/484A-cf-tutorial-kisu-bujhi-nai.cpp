#include <bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d",&x)
#define sf(x) scanf("%f",&x)

#define pi(x) printf("%d\n",x)
#define pf(x) printf("%.4f\n",x)

#define ll long long int

#define sll(x) scanf("%I64d",&x);
#define pll(x) printf("%-I64d\n",x);

ll f(ll l, ll r){
    ll ret = 0;
    if(r == l){ ret = l; return ret; }
    ll b = log2(r);
    ll temp = 1; 
    temp = temp<<b;
    ret = temp - 1;
    if(temp<=l){
        ret = f(l-temp, r-temp)+temp;
        return ret;
    }
    temp = (temp<<1) - 1;
    if(temp<=r){    ret = temp; return ret; }




    return ret;
}
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
    
    while(n--){
        ll l,r;
        cin>>l>>r;
        ll ans = f(l,r);
        cout<<ans<<"\n";
    }
	return 0;
}
