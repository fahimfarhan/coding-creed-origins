#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

typedef long long int ll;
// #define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MODULO = 1e9+7;

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


 int n,m;
 ll *a;
 vector<int> *g;
bool *isvisited;
//bool *isvisited_k;

ll maximus;

//void yo(){  for(int i=0; i<=n; i++){    isvisited_k[i] = false; }   }

void k_dfs_visit(int u, int parent,int grandparent, int k){
    if(k==0){
        return;
    }
    //isvisited_k[u]=true;
    a[u]++;
    int k1 = k-1;
    int v=0;
    for(int i=0; i<g[u].size(); i++){
        v = g[u][i];
        if( (!isvisited[v]) && (v!=parent) ){
            k_dfs_visit(v,u,parent, k1);
        }
    }

    //isvisited_k[u] = false;

}

void dfs_visit(int u, int parent, int grandparent){
    cout<<u<<"\n";
    
    if(a[u]>maximus){   maximus = a[u]; /*cout<<maximus<<"\n";*/    }
    isvisited[u] = true;
    // yo();
    k_dfs_visit(u,parent,grandparent, 2);
    int v=0,w=0;

    for(int j=0; j<g[u].size();j++ ){
                int w = g[u][j];
                a[w]++;    
            }

    for(int i=0; i<g[u].size(); i++){
        v = g[u][i];
        if(!isvisited[v]){
            dfs_visit(v, u, parent);
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
    m = n-1;
    g = new vector<int>[n+1];
    a = new ll[n+1];
    isvisited = new bool[n+1];
    //isvisited_k = new bool[n+1];

    for(int i=1; i<=n; i++){    cin>>a[i]; isvisited[i] = false;    }

    int x,y;
    
    for(int i=0; i<m; i++){
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int maximus_node; ll maximus_power;
    maximus_power = -1000000000; maximus_node  = 1;
    int degree, mypow;
    for(int i=1; i<=n; i++){
        degree = g[i].size();
        mypow = a[i]+degree;
        if( mypow > maximus_power ){ maximus_node= i; maximus_power = mypow; }
        else if(mypow == maximus_power){
            if(a[i]>a[maximus_node]){ maximus_node= i; maximus_power = mypow;  }
        }
    }

    maximus = -1000000000;
    int parent = 0, grandparent = 0;
    cout<<maximus<<" "<<maximus_node<<"\n";
    dfs_visit(maximus_node, parent, grandparent);
    cout<<maximus<<"\n";
    for(int i=1; i<=n; i++){    cout<<a[i]<<" "; }
    delete[] g;
    delete[] a;
    delete[] isvisited;
    //delete[] isvisited_k;
    return 0;
}
