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

	long long int T, a,b,c,s;
    cin>>T;
    while(T--){
        cin>>s>>a>>b>>c;
        long long int n = (int)s/(c);
        long long int add = (int)n/a;
        long long int ans = n+add*b;
        cout<<ans<<"\n";
    }
	return 0;
}
