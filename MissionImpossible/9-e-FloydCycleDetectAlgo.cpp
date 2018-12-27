#include <bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d",&x)
#define sf(x) scanf("%f",&x)

#define pi(x) printf("%d\n",x)
#define pf(x) printf("%.4f\n",x)

#define ll long long int

#define sll(x) scanf("%I64d",&x);
#define pll(x) printf("%-I64d\n",x);
bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


int n,m;
vector<int> *g;
bool *isvisited;
vector<int> cycle;
int cycle_count=0;
vector<pair<int, int> > markForDeletion;

void print_cycle(){
    cycle_count++;
    cout<<"cycle#"<<cycle_count<<": \n";
    for(int i=0; i<cycle.size(); i++){
        cout<<cycle[i]<<" ";
    }cout<<cycle[0]<<"\n";
}

void dfs(int u){
    isvisited[u] = true;
    cycle.push_back(u);
    //vector<int> markForDeletion;
    for(int i=0; i<g[u].size(); i++){
        int v = g[u][i];
        if(!isvisited[v]){  dfs(v); }
        else{
            // cycle detected!
            //g[u].erase(g[u].begin()+i);
            markForDeletion.push_back({u,i});
            print_cycle();
        }
    }
    /*
    for(int i=0; i<markForDeletion.size(); i++){
        g[i].erase(g[i].begin() + markForDeletion[i]);
    }*/
    cycle.pop_back();
}

void floydAlgo(){
    for(int i=1; i<=n; i++){
        if(!isvisited[i]){
            dfs(i);
        }
    }
    int u,v;
    for(int i=0; i<markForDeletion.size(); i++){
        u = markForDeletion[i].first;
        v = markForDeletion[i].second;
        g[u].erase(g[u].begin()+v);
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
    g  = new vector<int>[n+1];
    isvisited = new bool[n+1];

    for(int i=0; i<=n; i++){    isvisited[i] = false;   }

    int a,b;
    for(int i=0; i<m; i++){ cin>>a>>b; g[a].push_back(b);  }

    floydAlgo();

    for(int i=1; i<=n; i++){
        cout<<i<<" --> ";
        for(int j=0; j<g[i].size(); j++ ){
            cout<<g[i][j]<<" ";
        }cout<<"\n";
    }
    
    if(!g)delete[] g;
    if(!isvisited)delete[] isvisited;
  
  return 0;
}
