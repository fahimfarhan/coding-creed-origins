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
    ll T, ans, minimus, *a, *cf;
    ans = 0;
    cin>>n>>T;

    a = new ll[n];
    cf = new ll[n+2];
    minimus = INT_MAX;
    for(int i=0; i<n; i++){ cin>>a[i]; minimus = min(minimus, a[i]);  }
    sort(a,a+n);
    // minimus = a[0];
    cf[0] = minimus;

    for(int i=1; i<n; i++){ cf[i] = cf[i-1]+a[i];   }
    cf[n] = cf[n-1];
    cf[n+1] = cf[n];
    while(T>=minimus){
        // int lb = lower_bound(cf, cf+n, T) - cf;
        int lb = 0;
        for(int i=0; i<n; i++){
            if(cf[i]>T){lb = i-1; break;}
        }
        if(lb<0){   break; }
        ll d = (ll)T/cf[lb];
        T = T%cf[lb];
        
        ans = ans + d*(lb+1);  // WATCH OUT!!!
        cout<<ans<<" "<<T<<" "<<lb<<" "<<cf[lb]<<"\n";
    }

    cout<<ans<<"\n";
    delete[] a;
    delete[] cf;
	return 0;
}
