#include <bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d",&x)
#define sf(x) scanf("%f",&x)

#define pi(x) printf("%d\n",x)
#define pf(x) printf("%.4f\n",x)

#define ll long long int

#define sll(x) scanf("%I64d",&x);
#define pll(x) printf("%-I64d\n",x);

#define IS_DIRECTED false
int n,m;
vector< pair<int, int> > *g;
bool *isvisited;
queue<int> q;
int *dis;
int *parent;
int src;

void dijkstra(){
    src = 1;
    q.push(1);
    parent[src] = NULL;
    dis[1] = 0;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        isvisited[u] = true;
        for(int i=0; i<g[u].size(); i++){
            int v = g[u][i].first;
            int w = g[u][i].second; // dis(u,v)
            if(!isvisited[v]){  q.push(v); }
            if(dis[v]>dis[u]+w){ // if dis (v) > dis (u) + dis(u,v)
                dis[v] = dis[u] + w;
                parent[v] = u;
            }

        }
    }
}

void printer(){
    for(int i=01; i<=n; i++){
        cout<<dis[i]<<" ";
    }cout<<"\n";

    for(int i=1; i<=n; i++){
        stack<int> st;
        int node = i;
        while(node!=NULL){
            st.push(node);
            node = parent[node];
        }

        cout<<"Shortest path "<<src<<" - "<<i<<" : ";
        while(!st.empty()){ node = st.top(); st.pop(); cout<<node<<" "; }
        cout<<"\n";        
    }
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

    cin>>n>>m;
    g = new vector< pair<int, int> >[n+1];
    isvisited = new bool[n+1];
    dis = new int[n+1];
    parent = new int[n+1];

    for(int i=0; i<=n; i++){    isvisited[i] = false; dis[i] = INT_MAX; parent[i] = NULL; }
    int a,b,w;
    for(int i=0; i<m; i++){ 
        cin>>a>>b>>w; g[a].push_back({b,w}); 
        if(!IS_DIRECTED) g[b].push_back({a,w}); 
    }

    dijkstra();
    printer();
    if(!g)delete[] g;
    if(!isvisited)delete[] isvisited;
    if(!dis)delete[] dis;

	return 0;
}
