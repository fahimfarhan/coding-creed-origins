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
    ll T,min,ans, *a;
    ans = 0;
    min = INT_MAX;
    cin>>n>>T;
    a = new ll[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
        if(a[i]<min){   min = a[i]; }
    }

    int j = 0;
    while(T>=min){
        if(T>=a[j]){ T=T-a[j]; ans++;   }
        j=(j+1)%n;
    }
    cout<<ans<<"\n";
    if(!a)delete[] a;
	return 0;
}
