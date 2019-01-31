#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);
void dfs();
void dfsvisit(int i);


int n,m;
vector< int > *g;
bool *isvisited;
vector<int> path;

void dfs(){
    for(int i=1; i<=n; i++){
        if(!isvisited[i]){
            dfsvisit(i);
        }
    }
}

void dfsvisit(int u){
    isvisited[u] = true;
    path.push_back(u);
    sort(g[u].begin(), g[u].end());
    int v = 0;
    for(int i=0; i<g[u].size(); i++){
        v = g[u][i];
        if(!isvisited[v]){
            dfsvisit(v);
        }
    }
}

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

    cin>>n>>m;

    g = new vector<int>[n+1];
    isvisited = new bool[n+1];
    for(int i=0; i<=n; i++){    isvisited[i] = false;   }
    int a,b;
    for(int i=1; i<=m; i++){
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs();
    for(int i=0; i<path.size(); i++){
        cout<<path[i]<<" ";
    }cout<<"\n";

    
        
  return 0;
}

