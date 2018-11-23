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

	ll n,a,b,k, T;
    cin>>T;
    while(T--){
        n=0;
        cin>>a>>b>>k;
        if(k%2==1){ n=a;   }
        k = k>>1;
        n = n+ k*a - k*b;
        cout<<n<<"\n";
    }
	return 0;
}
