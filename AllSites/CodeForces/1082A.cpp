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

	int T;
    ll n,x,y,d, ans;
    cin>>T;
    while(T--){
        ans = INT_MAX;
        cin>>n>>x>>y>>d;
        // case 1: direct x to y
        if((x-y)%d == 0){
            ans = (x-y)/d;
        }else{
            // x to forward

            ll forward=INT_MAX, backward=INT_MAX;
            if((n-y)%d == 0) forward = ceil( (1.0*(n-x))/d) + (n-y)/d;
            if( (y-1)%d == 0 ) backward = ceil(1.0*(x-1)/d) + (y-1)/d;

            if(forward <0){ forward = INT_MAX; }
            if(backward < 0){ backward = INT_MAX;}
            ans = min(forward, backward);
            if(ans < 0){    ans = -1; }
        }
        cout<<ans<<"\n";

    }
	return 0;
}
