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
    ll *a;
    ll b, x;
    cin>>n;
    a = new ll[n+1];
    for(int i=0; i<=n; i++){    a[i] = 0;   }
    cin>>x;
    a[1] = 0;
    a[n] = x;
    for(int i=2; i<=n/2; i++){
        cin>>x;
        b = min(a[n-i+2] , x - a[n-i+2]);
        a[i]  = max(a[i-1], b);
        a[n-i+1] = x - a[i];
    }
  for(int i=1; i<=n; i++){
      cout<<a[i]<<" ";
  }cout<<"\n";

  delete[] a;
  return 0;
}
