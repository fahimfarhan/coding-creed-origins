#include<bits/stdc++.h>

using namespace std;

int n,m,q;
vector<int> *g;
bool *isvisited;
int *xor_value;

int dfs_visit(int u, int parent){
    //isvisited[u] = true;
    int v=0, x=u;
    for(int i=0; i<g[u].size(); i++){
        v = g[u][i];
        if(v!=parent){
            x=x^dfs_visit(v, u);
        }
    }
    xor_value[u]=x;
    return xor_value[u];


}


void dfs(){
    for(int i=0; i<=n; i++){    isvisited[i]=false;     }
    for(int i=1; i<=n; i++){
        if(!isvisited[i]){
            dfs_visit(i,0);
        }
    }
}

int query(int u){   return xor_value[u];    }

int main()
{

    cin>>n>>m>>q;
    g = new vector<int>[n+1];
    isvisited = new bool[n+1];
    xor_value = new int[n+1];
    int a,b;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs();
    for(int i=1; i<=n; i++){    cout<<xor_value[i]<<" "; }cout<<"\n";

    while(q--){
        cin>>m; 
        m = query(m);
        cout<<m<<"\n";
    }

    delete[] xor_value;
    delete[] isvisited;
    delete[] g;

    return 0;
}