#include <bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d",&x)
#define sf(x) scanf("%f",&x)

#define pi(x) printf("%d\n",x)
#define pf(x) printf("%.4f\n",x)

#define ll long long int

#define sll(x) scanf("%I64d",&x);
#define pll(x) printf("%-I64d\n",x);


// ll *a;

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
    
    cin>>n;
    ll a[3];
    a[0] = 1;
    a[1] = 0;
    a[2] = 0;

    int i=2;
    for(int j=2; j<=n; j++){
        a[i] = 2*a[i-1]+3*a[i-2];
        a[i] = a[i]%1000000007;

        a[i-2] = a[i-1];
        a[i-1] = a[i];
    }
    cout<<a[2]<<"\n";

    // if(!a)delete[] a;
	return 0;
}
