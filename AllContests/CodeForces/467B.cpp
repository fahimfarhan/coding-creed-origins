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

	int n,m,k;
    int  ans = 0;
    int *a;
    cin>>n>>m>>k;
    a = new int[m+1];

    for(int i=0; i<=m; i++){    cin>>a[i];  }

    for(int i=0; i<m; i++){
        int temp = (a[i]^a[m]);
        int setCount = __builtin_popcount(temp); // manually koray agerbar vul hoisilo :'( 
        if(setCount<=k){    ans++; }
    }

    cout<<ans<<"\n";

    delete[] a;
	return 0;
}
