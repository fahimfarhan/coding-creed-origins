#include <bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d",&x)
#define sf(x) scanf("%f",&x)

#define pi(x) printf("%d\n",x)
#define pf(x) printf("%.4f\n",x)

#define ll long long int

#define sll(x) scanf("%I64d",&x);
#define pll(x) printf("%-I64d\n",x);
bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


vector<int> *g;
bool *isvisited;





int main(int argc, char const *argv[])
{
	/* code */
  /* Soln soln */
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int T;

ll  n,m, sn;
    ll dp[2][10005];
    ll cf[10005];
    cf[1] = 1;
    dp[0][01] = 1;
    dp[01][01] = 6;
    
    for(int i=2; i<10005; i++){
        dp[1][i] = (dp[1][i-1]+6)%1000000007;
        dp[0][i] = (dp[0][i-1]+dp[1][i-1] )%1000000007;

        //cout<<dp[0][i]<<" ";
    }

    for(int i=2; i<10005; i++){
        cf[i] = cf[i-1]+dp[0][i];
        // cout<<cf[i]<<" ";
    }
 
  cin>>T;
  while(T--){
      cin>>m>>n;
        sn = (m*cf[n]) % 1000000007;
        cout<<sn<<"\n";
  }
  return 0;
}
