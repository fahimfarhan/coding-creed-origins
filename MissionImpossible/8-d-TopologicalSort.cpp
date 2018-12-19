#include <bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d",&x)
#define sf(x) scanf("%f",&x)

#define pi(x) printf("%d\n",x)
#define pf(x) printf("%.4f\n",x)

#define ll long long int

#define sll(x) scanf("%I64d",&x);
#define pll(x) printf("%-I64d\n",x);

void dfsvisit();
void dfs(int i);

int n,m;
vector<int> *g;
stack<int> st;
bool *isvisited;

void dfsvisit(){
    for(int i=1; i<=n; i++){
        if(!isvisited[i]){  dfs(i); }
    }
}

void dfs(int u){
    isvisited[u] = true;
    for(int i=0; i<g[u].size(); i++){
        int v = g[u][i];
        if(!isvisited[v]){  dfs(v); }
    }
    st.push(u);
}

void printer(){
    cout<<"\n------TOPOLOGICALLY SORTED ORDER------\n";
    while(!st.empty()){
        int node = st.top();
        cout<<node<<" ";
        st.pop();
    }
    cout<<"\n";
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
    g = new vector<int>[n+1];
    isvisited = new bool[n+1];
    for(int i=0; i<=n; i++){    isvisited[i] = false;   }
    int u,v;
    for(int i=0; i<m; i++){
        cin>>u>>v;
        g[u].push_back(v);
    }

    dfsvisit();
    printer();

    if(!g)delete[] g;
    if(!isvisited)delete[] isvisited;
	return 0;
}
