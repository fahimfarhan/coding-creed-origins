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

	int n;
    vector<int> v;
    cin>>n;
    v.push_back(0);
    for(int i=0; i<n; i++){
        int x; cin>>x;
        v.push_back(x);
    }

    for(int i=1; i<=n; i++)
    {
        //int x = v[i];
        cout<<v[v[i]]<<"\n";
    }
	return 0;
}
