#include <bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d",&x)
#define sf(x) scanf("%f",&x)

#define pi(x) printf("%d\n",x)
#define pf(x) printf("%.6lf\n",x)

#define ll long long int

#define sll(x) scanf("%I64d",&x);
#define pll(x) printf("%-I64d\n",x);

vector<int> *g;
bool *is_visited;
int n;

// void dfs_visit();  since tree and not forest, we dont need this ! :o

double dfs(int u){
  double ans = 0;
  is_visited[u] = true;
  int k = 0;
  for(int i=0; i<g[u].size(); i++){
    int v = g[u][i];
    if(!is_visited[v]){
      k++; ans+=dfs(v);
    }
  }
  if(k!=0){ ans=(ans/k)+1; }
  return ans;
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
  g = new vector<int>[n+1];
  is_visited = new bool[n+1];

  for(int i=0; i<=n; i++){  is_visited[i] = false;  }
  for(int i=0; i<n-1; i++){
    int u,v;
    cin>>u>>v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  pf(dfs(1));
  // cout<<dfs(1)<<"\n";
  if(!is_visited)delete[] is_visited;
  if(!g)delete[] g;
	return 0;
}
