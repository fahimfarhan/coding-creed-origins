#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


int n,k;
priority_queue<ll> pq;
map<ll,int> mp;
ll *p,*c;

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

    cin>>n>>k;
    p = new ll[n]; c = new ll[n];
    for(int i=0; i<n; i++){ cin>>p[i]; mp[p[i]] = i; }
    for(int i=0; i<n; i++){ cin>>c[i]; }

    sort(p,p+n);

    for(int i=0; i<n; i++){
        
    }
  
  return 0;
}

