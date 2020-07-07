#include <bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d",&x)
#define sf(x) scanf("%f",&x)

#define pi(x) printf("%d\n",x)
#define pf(x) printf("%.4f\n",x)

#define ll long long int

#define sll(x) scanf("%I64d",&x);
#define pll(x) printf("%-I64d\n",x);

#define WHITE 2
#define BLUE 1
#define RED 0

int n,m;
vector<int> *g;
queue<int> q;
bool *isvisited;
int *color;

string bfs(){
    color[1] = BLUE;
    //isvisited[1] = true;
    q.push(1);
    while(!q.empty()){
        int u = q.front();
        int nextLevelColor ;
        if(color[u] == BLUE){   nextLevelColor = RED; }
        else if(color[u] == RED){   nextLevelColor = BLUE; }
        isvisited[u] = true;
        q.pop();

        for(int i=0; i<g[u].size(); i++){
            int v = g[u][i];
            if( (!isvisited[v] )  ){
                if(( color[u] == color[v] )){
                    return "NO!";
                }
                color[v] = nextLevelColor;
                q.push(v);
            }
        }


    }
    return "YES!";
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
// 1 based indexing
    cin>>n>>m;
    g = new vector<int>[n+1];
    isvisited = new bool[n+1];
    color = new int[n+1];

    for(int i=0; i<=n; i++){    isvisited[i] = false; color[i] = WHITE; }
    int a,b;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    cout<<bfs()<<"\n";
	
	return 0;
}
