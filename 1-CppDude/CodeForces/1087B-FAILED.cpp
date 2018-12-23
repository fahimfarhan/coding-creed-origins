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


int n,m;
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

  ll n; int k;
  cin>>n>>k;
  ll a,b; int x=0;
  // cout<<sqrt(n)<<"\n";
  int i = 1*k+1;
  for(int i=1; i<=sqrt(n); i++){
      if( (n%i) == 0 ){
          a = i; b = n/i;
          // if(b>a){  a=a^b; b=a^b; a=a^b;}
          
            x = a*k+b;
            if( ((x/k)*(x%k)) == n){
cout<<x<<"\n";
          break;

            }
                    
           
      }
  }

  //cout<<x<<"\n";

  
  return 0;
}
