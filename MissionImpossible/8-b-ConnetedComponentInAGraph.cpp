#include <bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d",&x)
#define sf(x) scanf("%f",&x)

#define pi(x) printf("%d\n",x)
#define pf(x) printf("%.4f\n",x)

#define ll long long int

#define sll(x) scanf("%I64d",&x);
#define pll(x) printf("%-I64d\n",x);
	
int n,m;
vector<int> *g;
bool *isVisited;
int comp_count;
vector<int> v;

void DFS_Visit();
void dfs(int u);

void DFS_Visit(){
    comp_count = 0;
    for(int i=01; i<=n; i++){
        if(!isVisited[i]){
            comp_count++;
            dfs(i);
            v.push_back(0);
        }
    }
}

void dfs(int u){
    isVisited[u] = true;
    v.push_back(u);
    for(int i=0; i<g[u].size(); i++){
        int v = g[u][i];
        if(!isVisited[v]){
            dfs(v);
        }
    }
}

void printer(){
    cout<<"\n----------\n"<<comp_count<<"\n----------\n";
    for(int i=0; i<v.size(); i++){
        if(v[i] == 0){ cout<<"\n"; }
        else{   cout<<v[i]<<" "; }
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
    g = new vector<int>[n+1];
    isVisited = new bool[n+1];
    for(int i=0; i<=n; i++){    isVisited[i] = false; }
    int u,v;
    for(int i=0; i<m; i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    DFS_Visit();
    printer();
    delete[] g;
	return 0;
}
