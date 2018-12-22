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
    ll T;
    ll ans = 0;
    ll *a, *cf;

    cin>>n>>T;
    a = new ll[n+1];
    cf = new ll[n+1];
    a[0] = 0;
    for(int i=01; i<=n; i++){
        cin>>a[i];
    }

    sort(a,a+n+1);
    cf[0] = a[0];
    for(int i=1; i<=n; i++){ cf[i] = cf[i-1]+a[i];   }
    
    for(int i=0; i<=n; i++){    cout<<a[i] <<" "; }
    cout<<"\n";

    for(int i=0; i<=n; i++){    cout<<cf[i] <<" "; }
    cout<<"\n";
    
    int debug=0;
    while(true){
        debug++;
        if(debug==100){ break; }
        int m = upper_bound(cf,cf+n, T)-cf;
        if(m==0){   break;  }
        T=T-cf[m];
        ans+=m;

        cout<<ans<<" "<<T<<" "<<m<<" "<<cf[m]<<"\n";
    }
    cout<<ans<<"\n";
    if(!a)delete[] a;
    if(!cf)delete[] cf;
	return 0;
}
