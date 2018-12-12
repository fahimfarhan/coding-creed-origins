#include <bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d",&x)
#define sf(x) scanf("%f",&x)

#define pi(x) printf("%d\n",x)
#define pf(x) printf("%.4f\n",x)

#define ll long long int

#define sll(x) scanf("%I64d",&x);
#define pll(x) printf("%-I64d\n",x);

void dfsVisit();
void DFS(ll u);


int n;
ll *w;
bool *isVisited;
map<pair<ll,ll>,ll> mp;
vector<ll> *G; 
ll totalCost = INT_MIN;
ll gas = 0;
ll src=0;

void dfsVisit(){
    gas = 0;
    for(int i=0; i<=n; i++){    isVisited[i] =  false;  }
    for(int i=1; i<=n; i++){
        if(!isVisited[i]){
            DFS(i);
        }
    }
}
void DFS(ll u){
    isVisited[u] = true;
    gas += w[u];
    if(gas>totalCost){ totalCost = gas; }
    for(int i=0; i<G[u].size(); i++){
        ll v = G[u][i];
        pair<ll,ll> p(u,v);
        ll uvPathCost = mp[p];
        if(gas>=uvPathCost){
            gas-=uvPathCost;
            DFS(v);
            gas+=uvPathCost;
        }

    }
    gas-=w[u];
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
    w = new ll[n+1];
    G = new vector<ll>[n+1];
    isVisited = new bool[n+1];
    
    for(int i=01; i<=n; i++){   cin>>w[i];  }
    
    for(int i=1; i<n; i++){
        ll u,v,c;
        cin>>u>>v>>c;
        pair<ll,ll> p1(u,v), p2(v,u);
        mp[p1] = c;
        mp[p2] = c;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    for(int i=1; i<=n; i++){
        src = i;
        dfsVisit();
    }

    cout<<totalCost<<"\n";

    if(!w)delete[] w;
    if(!G)delete[] G;
	return 0;
}
