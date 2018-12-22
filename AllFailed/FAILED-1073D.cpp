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

	int64_t n, T,d,r, *a, *s;
    cin>>n>>T;
    s = new int64_t[n];
    
    for(int i=0; i<n; i++){
        cin>>a[i];
        // s[i]+=s[i-1];
    }
    sort(a,a+n);
    s[0] = a[0];

    for(int i=1; i<n; i++){
        s[i] = a[i]+s[i-1];   
    }

    d = T/s[n-1];
    
    r = T%s[n-1];
    int64_t ans = d*n;
    while(r>a[0]){
        int lb = lower_bound(s,s+n,r)-s;
        ans = ans+lb;
        r = r - s[lb];
    }
    cout<<ans<<"\n";
	return 0;
}
