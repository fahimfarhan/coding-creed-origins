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

	int m, n,r,d,k,T;
  string s, ans;
  char ch;
  cin>>T;
  while(T--){
    s = ""; ans = "";
    cin>>n>>k;
    // k = min(n,26);
    r = n%k;
    d = n/k;
    for(int i=0; i<k; i++){
      ch = ('a'+i);
      s = s+ch;
    }
    for(int i=0; i<d; i++){
      ans = ans + s;
    }
    for(int i=0; i<r; i++){
      ch = ('a'+i);
      ans = ans + ch;
    }
    cout<<ans<<"\n";
  }
	return 0;
}
