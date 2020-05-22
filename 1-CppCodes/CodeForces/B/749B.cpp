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
    set<pair<int, int> > s;
    int x[7], y[7];

    for(int i=0; i<3; i++){
        cin>>x[i]>>y[i];
    }

    x[3] = x[0] + (x[1] - x[2]);
    y[3] = y[0] + (y[1] - y[2]);

    x[4] = x[0] - (x[1] - x[2]);
    y[4] = y[0] - (y[1] - y[2]);

    x[5] = x[01] + (x[0] - x[2]);
    y[5] = y[01] + (y[0] - y[2]);

    x[6] = x[01] - (x[0] - x[2]);
    y[6] = y[01] - (y[0] - y[2]);
    
    for(int i=3; i<7; i++){ pair<int, int> p(x[i], y[i]); s.insert(p); }

    set<pair<int, int> > :: iterator it;
    cout<<3<<"\n";
    for(it = s.begin(); it!=s.end(); it++){
        cout<<it->first<<" "<<it->second<<"\n";
    }
	return 0;
}
