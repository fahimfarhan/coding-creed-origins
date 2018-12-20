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
vector<int> *g, *gt;
bool *isvisitedg, *isvisitedgt;
stack<int> st;
vector<int> *scc;
int scc_count;

void printer(){
    cout<<"Total # of scc = "<<scc_count<<"\n";
    
    for(int i=1; i<=scc_count; i++){
        for(int j=0; j<scc[i].size(); j++){
            cout<<scc[i][j]<<" ";
        }cout<<"\n";
    }
}

void dfsgt(int u){
    isvisitedgt[u] = true;
    scc[scc_count].push_back(u);
    for(int i=0; i<gt[u].size(); i++){
        int v = gt[u][i];
        if(!isvisitedgt[v]){    dfsgt(v);   }
    }
}

void dfsvisitgt(){
    while(!st.empty()){
        
        int u = st.top(); st.pop();
        if(!isvisitedgt[u]){
            scc_count++;
            dfsgt(u);
        }
        
    }
}

void dfsg(int u){
    isvisitedg[u] = true;
    st.push(u);
    for(int i=0; i<g[u].size(); i++){
        int v = g[u][i];
        if(!isvisitedg[v]){ dfsg(v);    }
    }
}
void dfsvisitg(){
    for(int i=1; i<=n; i++){
        if(!isvisitedg[i]){ dfsg(i); }
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
  scc_count = 0;
    cin>>n>>m;
    
    g  = new vector<int>[n+1];
    gt = new vector<int>[n+1];
	scc = new vector<int>[n+1];
    isvisitedg = new bool[n+1];
    isvisitedgt = new bool[n+1];
    for(int i=0; i<=n; i++){    isvisitedg[i] = false; isvisitedgt[i] = false;   }
    int a,b;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        g[a].push_back(b);
        gt[b].push_back(a);
    }

    dfsvisitg();
    dfsvisitgt();
    printer();

    if(!g)delete[] g;
    if(!gt)delete[] gt;
    if(!isvisitedg)delete[] isvisitedg;
    if(!isvisitedgt)delete[] isvisitedgt;
    if(!scc)delete[] scc;
    return 0;
}
