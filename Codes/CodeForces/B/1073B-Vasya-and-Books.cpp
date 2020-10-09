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

	int n, top_stack;
    cin>>n;

    int a[n+1], b[n+1], pos[n+1];
    for(int i=1; i<=n; i++){
        cin>>a[i];
        pos[a[i]] = i;
    }
        top_stack = 0;
    for(int i=1; i<=n; i++){
        cin>>b[i];
        if(pos[b[i]]>top_stack){
            int ans = pos[b[i]] - top_stack;
            top_stack+=ans;
            cout<<ans<<" ";
        }else{
            cout<<0<<" ";
        }
    }
    cout<<"\n";
	return 0;
}
