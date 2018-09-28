#include <bits/stdc++.h>
using namespace std;
void dfs_algo();
void dfs(int u);
#define si(x) scanf("%d",&x)
#define sf(x) scanf("%f",&x)

#define pi(x) printf("%d\n",x)
#define pf(x) printf("%.4f\n",x)

#define ll long long int

#define sll(x) scanf("%I64d",&x);
#define pll(x) printf("%-I64d\n",x);

vector<int> *g;
bool *isVisited;
double *ans;
int n;

void dfs_algo(){
  for(int i=1; i<=n; i++){
    if(!isVisited[i]){
      dfs(i);
    }
  }
}

void dfs(int u){
  isVisited[u] = true;
  //ans[u] = 0;    
  if(g[u].size() == 0){
    return;
  }
  int k = 0;
  for(int i=0; i<g[u].size(); i++){
    int v = g[u][i];
    if(!isVisited[v]){
      dfs(v);
      k++;
      ans[u]+=ans[v];
    }
    
  }
  ans[u] = 1+(ans[u]/k);
  return;
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
  isVisited = new bool[n+1];
  ans = new double[n+1];

  for(int i=0; i<=n; i++){  ans[i] = 0; isVisited[i] = false; }

  dfs_algo();
  cout<<ans[1]<<"\n";

  if(!g)delete[] g;
  if(!isVisited)delete[] isVisited;
  if(!ans)delete[] ans;
	return 0;
}
