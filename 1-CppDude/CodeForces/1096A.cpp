#include <bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d",&x)
#define sf(x) scanf("%f",&x)

#define pi(x) printf("%d\n",x)
#define pf(x) printf("%.4f\n",x)

#define ll int64_t

#define sll(x) scanf("%I64d",&x);
#define pll(x) printf("%-I64d\n",x);
bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


int n,m;
vector<int> *g;
bool *isvisited;


pair<ll,ll> f(ll l, ll r){
    ll ans = 0;
    for(int i=l; i<r; i++){
            int j = r/i;

            for(int k=2; k<j; k++){
                ans = i*k;
                if(ans <=r && (i != ans)){
                    
                    return {i,ans}; 
                }
            }
        } 
}

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
    ll l,r;
     ;
    cin>>T;
    while(T--){
        cin>>l>>r;
         //pair<ll,ll> p = f(l,r);
         cout<<l<<" "<<2*l<<"\n";
    }
  
  return 0;
}
