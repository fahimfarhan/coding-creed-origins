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
bool *isvisited;
int *indeg;
queue<int> q;
vector<int> ts;
//void bfsvisit();
void bfs();

void bfs(){
    // fetch nodes with indeg == 0
    for(int i=1; i<=n; i++){
        if(indeg[i] == 0){  q.push(i);  }
    }

    while(!q.empty()){
        int u = q.front();
        ts.push_back(u);
        q.pop();
        isvisited[u] = true;
        for(int i=0; i<g[u].size(); i++){
            int v = g[u][i];
            indeg[v]--;
            if( !isvisited[v] && indeg[v] == 0 ) q.push(v);
        }
    }
}

void printer(){
    cout<<"\n--------TOPOLOGIAL SORT USING KAHN'S ALGO------\n";
    for(int i=0; i<ts.size(); i++){
        cout<<ts[i]<<" ";
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
    g=new vector<int>[n+1];
    isvisited = new bool[n+1];
    indeg = new int[n+1];
    for(int i=0; i<=n; i++){    isvisited[i] = false; indeg[i] = 0;       }
    
    int u,v;
    for(int i=0; i<m; i++){
        cin>>u>>v;
        g[u].push_back(v);
        indeg[v]++;
    }

    bfs();
    printer();

    delete[] g;
    delete[] isvisited;
    delete[] indeg;
	return 0;
}
