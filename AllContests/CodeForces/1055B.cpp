#include <bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d",&x)
#define sf(x) scanf("%f",&x)

#define pi(x) printf("%d\n",x)
#define pf(x) printf("%.4f\n",x)

#define ll long long int

#define sll(x) scanf("%I64d",&x);
#define pll(x) printf("%-I64d\n",x);

int n,m,l; ll ans;
ll *a;

int main(int argc, char const *argv[])
{
	/* code */
  /* Soln soln */
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

    cin>>n>>m>>l;
    ans = 0;
    a = new ll[n+2];
    a[0] = 0; a[n+1] = 0;
    
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }

    for(int i=1; i<=n; i++){
        if(a[i-1]<=l && a[i]>l){    ans++; }
    }

    ll q,pi, di;
    while(m--){
        cin>>q;
        if(q==0){
            cout<<ans<<"\n";
        }else if(q==1){
            cin>>pi>>di;
            if(a[pi]<=l&&a[pi]+di>l) ans+=1-(a[pi-1]>l)-(a[pi+1]>l);
			a[pi]+=di;
            
        }
    }

    if(!a)delete[] a;
	return 0;
}
