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
    cin>>n;
    ll *a;
    a = new ll[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }


    if(n == 2){
        cout<<"0"<<"\n";
    }else{
        sort(a,a+n);
        // case 1
        ll a1 = a[n-1] - a[1];
        // case 2
        ll a2 = a[n-2] - a[0];

        cout<<min(a1,a2)<<"\n";

    }
  
  return 0;
}
