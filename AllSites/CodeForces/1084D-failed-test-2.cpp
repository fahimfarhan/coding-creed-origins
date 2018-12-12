#include <bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d",&x)
#define sf(x) scanf("%f",&x)

#define pi(x) printf("%d\n",x)
#define pf(x) printf("%.4f\n",x)

#define ll long long int

#define sll(x) scanf("%I64d",&x);
#define pll(x) printf("%-I64d\n",x);


vector< pair <ll, ll> > *g;
int n;
ll *w;
bool *isVisited;
ll curr = 0;

ll dfs(ll u){
    ll ret = w[u];
    isVisited[u] = true;
    curr = max(curr, w[u]);

    for(int i=0; i<g[u].size(); i++){
        
        ll v = g[u][i].first;
        ll c = g[u][i].second;
        if(!isVisited[v] && (curr-c>=0) ){
            ll weight = dfs(v) - c;
            curr = max(curr, ret+weight);
            ret = max(ret, weight+w[v]);
        }

    }
    return ret;
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

    cin>>n;
    g = new vector< pair<ll, ll> >[n+1];
    w = new ll[n+1];
    isVisited = new bool[n+1];

    for(int i=01; i<=n; i++){   cin>>w[i];  }
    
    ll u,v,c;
    for(int i=1; i<=n-1; i++){
        cin>>u>>v>>c;
        pair<ll, ll> p1(u,c), p2(v,c); 
        g[u].push_back(p1);
        g[v].push_back(p2);    
    }
    ll finalAns = 0;
    for(int i=1; i<=n; i++){
        for(int i=0; i<=n; i++){    isVisited[i] = false; }
        finalAns = max(finalAns, dfs(i));
    }
    cout<<finalAns<<"\n";
    delete[] g;
    delete[] w;
    delete[] isVisited;

	return 0;
}
