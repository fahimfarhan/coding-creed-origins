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
//vector<int> *g;
bool *isvisited;
int **g;
int **gf;
//bool *isvisited;

vector<int> p;

int s=0,t=0, MaxFlow=0;

void dfs(int u){
    p.push_back(u);
    isvisited[u] = true;
    for(int v=1; v<=n; v++){
        if(v!=u){
            int w = gf[u][v];
            if(w>0 && !isvisited[v]){
                dfs(v);
            }
        }
    }
}

void dfsvisit(){
    while(!p.empty()){  p.pop_back();   }
    for(int i=0; i<=n; i++){    isvisited[i] = false;   }
    dfs(s);
}

void FordFulkerson(){
    // find a path
    MaxFlow = 0;
    while(true){
        dfsvisit();
        if(p.empty()){  break; }
        int len = p.size();
        int minimus = INT_MAX;
        for(int i=0; i<len-1; i++){
            int u = p[i]; int v = p[i+1];
            if(gf[u][v]<minimus){   minimus = gf[u][v];     }
        }
       for(int i=0; i<len-1; i++){
            int u = p[i]; int v = p[i+1];
            gf[u][v] = gf[u][v] - minimus;
            gf[v][u] = gf[v][u] + minimus;
            MaxFlow+=minimus;
        }
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
    cin>>s>>t;
    /*g = new int*[n+1];*/
    gf = new int*[n+1];

    for(int i=0; i<=n; i++){    /*g[i] = new int[n+1];*/   gf[i] = new int[n+1];  }
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            gf[i][j] = -1;
        }
    }
    isvisited = new bool[n+1];
    
    int a,b,c;
    for(int i=0; i<m; i++){
        cin>>a>>b>>c;
        gf[a][b] = c;
        gf[b][a] = 0;
    }

    FordFulkerson();
    cout<<"The max flow is: "<<MaxFlow<<"\n";

    delete[] isvisited;
    for(int i=0; i<=n; i++){    /*delete[] g;*/ delete[] gf;    }
    delete[] g;
    delete[] gf;
	return 0;
}
