#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


int n,m,d;
vector<int> *g;
bool *isvisited;
int *p;

vector<int> *nodes;

void resetIsVisited(){    for(int i=0; i<=n; i++){    isvisited[i]=false; }   }

void dfs_visit(int IndexOfP, int u, int k){
    isvisited[u] = true;
    nodes[IndexOfP].push_back(u);
    int k1 = k-1;
    if(k1==0){   return; }

    int v = 0;
    for(int i=0; i<g[u].size(); i++){
        v = g[u][i];
        if(!isvisited[v]){
            dfs_visit(IndexOfP,v,k1);
        }
    }
}

void kDepthLimitedDFS(){
    int k;
    for(int i=0; i<m; i++){
        resetIsVisited();
        k = d;
        k = k+1;
        dfs_visit(i, p[i], k);
    }
}



int main(int argc, char const *argv[])
{
    /* code */
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    /*
    cout << setprecision(8);
    cout << num1 << endl;
    */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>d;
    
    g = new vector<int>[n+1];
    isvisited = new bool[n+1];
    p = new int[m+1];
    nodes = new vector<int>[m+1];

    for(int i=0; i<m; i++){    cin>>p[i];  }
    int a,b;
    for(int i=0; i<n; i++){
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    kDepthLimitedDFS();
    
    int size, minimus = INT_MAX;
    for(int i=0; i<m; i++){
        size = nodes[i].size();
        minimus = min(minimus, size);
    }

    cout<<minimus<<"\n";

    delete[] p;
    delete[] isvisited;
    delete[] g;
    delete[] nodes;
    return 0;
}
