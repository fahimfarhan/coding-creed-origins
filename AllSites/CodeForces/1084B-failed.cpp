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

	
    ll n,a,ans, minimus,sum,s;
    cin>>n>>s;
    minimus = INT_MAX;
    sum = 0;
    for(int i=0; i<n; i++){
        cin>>a;
        sum+=a;
        minimus = min(minimus, a);
    }

    if(s > sum){
        cout<<"-1\n";
    }else{
        sum-=minimus;
        ll remaining = sum - s;
        ans = minimus - remaining;
    cout<<-ans<<"\n";
	
    }

    return 0;
}
