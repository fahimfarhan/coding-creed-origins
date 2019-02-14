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
  string s,t;
  cin>>n;
  cin>>t;
  s = "";

  int j=0;
  int k = 0;
  
    for(int i=1; i<=n; i++){
        if( (i*(i+1)/2) == n){ k=i; break; }
    }

    for(int i=1; i<=k; i++){
        j = j+i;
        s = s +  t[j-1];
        // if(i == k ){    break; }

    }

    cout<<s<<"\n";


  
  return 0;
}
