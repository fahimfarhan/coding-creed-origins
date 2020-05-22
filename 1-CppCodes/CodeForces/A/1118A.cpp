#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int

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
  /*
  cout << setprecision(8);
  cout << num1 << endl;
  */
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

    int m,a,q,b;
    int64_t n,ans;
    cin>>q;
    while(q--){
        cin>>n>>a>>b;
        ans = 0;
        ans = n/2*b+a*(n%2);
        ans = min(ans, n*a);
        cout<<ans<<"\n";
    }
  
  return 0;
}

