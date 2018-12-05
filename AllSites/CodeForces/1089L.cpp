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

	int n,k;
    int *a;
    ll *b;
map<int, vector<pair<int, ll> > mp;
    cin>>n>>k;
    a = new int[n+1];
    b = new ll[n+1];

    for(int i=1; i<=n; i++){
        cin>>a[i];
        
    }
    for(int i=1; i<=n; i++){
        cin>>b[i];
    }

    for(int i=1; i<n; i++){
        pair
        mp[a[i]].push_back();
    }


    delete[] a;
    delete[] b;
	return 0;
}
