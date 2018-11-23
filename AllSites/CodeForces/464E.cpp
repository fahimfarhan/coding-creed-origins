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
vector<pair<int, int> > *g;
bool *visited;
int *p;

queue<int> q;

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
    g = new vector<pair<int, int> >[n+1];
    p = new int[n+1];
    visited = new bool[n+1];

    for(int i=0; i<=n; i++){    p[i] = 0; visited[i] = false;}

    int u,v,x;
    for(int i=0; i<m; i++){
        cin>>u>>v>>x;
        pair<int, int> p1,p2;
        p1.first = v; p1.second = x;
        p2.first = u; p2.second = x;
        g[u].push_back(p1);
        g[v].push_back(p2);
    }
    return 0;
}
