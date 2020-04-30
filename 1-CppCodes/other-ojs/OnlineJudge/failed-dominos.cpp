#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int T, n,m, u, v;
vector<int> *g;
bool *isvisited;

stack<int> st;

void initIsVisited() {
    for(int i=0; i<=n; i++) {    isvisited[i] = 0;  }
}

void dfsVisit(int u, bool isTopologicalSort) {
    st.pop();
    isvisited[u] = 1;
    int v = 0;
    for(int i=0; i<g[u].size(); i++ ) {
        v = g[u][i];
        if(!isvisited[v]) {
            dfsVisit(v, isTopologicalSort);
        }
    }
    if(isTopologicalSort) {
        st.push(u);
    }

}

int dfs(bool isTopologicalSort) {
        int kount = 0;
    if(isTopologicalSort) {
        for(int i=1; i<=n; i++) {
            if(!isvisited[i]) {
                dfsVisit(i, isTopologicalSort);
            }
        }
    }else {
        while( !st.empty() ) {
            kount++;
            int u = st.top();
            if(!isvisited[u]) {
                dfsVisit(u, isTopologicalSort);
            }
        }
    }
    return kount;
}

void topologicalSort() {
    dfs(true);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>T;
    while(T--) {
        cin>>n>>m;
        isvisited = new bool[n+1];
        g = new vector<int>[n+1];

        for(int i=0; i<m; i++) {
            cin>>u>>v;
            g[u].push_back(v);
        }

        // topological sort
        initIsVisited();
        topologicalSort();

        // dfs
        initIsVisited();
        int kount = dfs(false);
        cout<<kount<<"\n";

        delete[] isvisited;
        delete[] g;
    }
    return 0;
}