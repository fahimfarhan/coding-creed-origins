#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);

int n,m, minimus;
vector<int> *g;
bool *isvisited;
int *c;

void dfs_visit(int u, int parentColor){
    
    isvisited[u] = true;
    int currColor = parentColor;
    if(parentColor!=c[u]){
        minimus++;
        currColor = c[u];
    }

    int v = 0;
    for(int i=0; i<g[u].size(); i++){
        v = g[u][i];
        if(!isvisited[v]){
            dfs_visit(v, currColor);
        }
    }

}

void dfs(){
    minimus = 0;
    for(int i=1; i<=n; i++){
        if(!isvisited[i]){
            dfs_visit(i,0);
        }
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
    cin>>n;
    m=n-1;
    
    c = new int[n+1];
    isvisited = new bool[n+1];
    g = new vector<int>[n+1];

    for(int i=0; i<=n; i++){    c[i]=0; isvisited[i]=0;     }

    int p;
    for(int i=2; i<=n; i++){
        cin>>p;
        g[i].push_back(p); g[p].push_back(i);
    }

    for(int i=1; i<=n; i++){    cin>>c[i];  }
    
    minimus=0;
    dfs();
    cout<<minimus<<"\n";


    if(!g)delete[] g;
    if(!isvisited)delete[] isvisited;
    if(!c)delete[] c;
    
    return 0;
}
