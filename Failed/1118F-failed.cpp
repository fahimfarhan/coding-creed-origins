#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)
#define UNMARKED 0 
#define RED 1 
#define BLUE 2

#define ll long long int

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);
void dfs(short color);
void dfsvisit(int u, short color);

int n,m;
short *a;
vector<int> *g;

map< pair<int, int> , int> mp;
bool *isvisited;
int edgeCount[3];

void dfs(short color){
    
    for(int i=1; i<=n; i++){
        if( (a[i] == color) && (!isvisited[i]) ){
            dfsvisit(i, color);
        }
    }
}

void dfsvisit(int u, short  color){
    isvisited[u] = true;
    int v;
    for(int i=0; i<g[u].size(); i++){
        v = g[u][i];
        if( (a[v] == color) && (!isvisited[v]) ){
            edgeCount[(int)color]++;
            dfsvisit(v,color);
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

    cin>>n;
    m=n-1;
    a = new short[n+1];
    g = new vector<int>[n+1];
    isvisited = new bool[n+1];
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }

    for(int i=0; i<=n; i++){    isvisited[i] = false; }

    int u,v;
    for(int i=0; i<m; i++){
        cin>>u>>v;
        g[u].push_back(v);  g[v].push_back(u);
        mp[{u,v}] = 0;      mp[{v,u}] = 0;
    }
    dfs(RED);
    dfs(BLUE);

    int ans = m - edgeCount[RED] - edgeCount[BLUE];
    cout<<ans<<"\n";

    
    if(!a)delete[] a;
    if(!g)delete[] g;
    if(!isvisited)delete[] isvisited;
  return 0;
}


