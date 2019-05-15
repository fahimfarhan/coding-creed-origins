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
vector<int> *g;
bool *isvisited;
int *mcount;
// vector<int> p;

int dfs_visit(int u, int depth){
    isvisited[u] = true;
    // p.push_back(u);
    int ret = depth;
    int v = 0;
    for(int i=0; i<g[u].size(); i++){
        v = g[u][i];
        if(!isvisited[v]){
            ret = max(ret, dfs_visit(v,(depth+1)) );
        }
    }
    mcount[u] = ret;
    return ret;
}

void dfs(){
    for(int i=0; i<=n;i++ ){    isvisited[i]=0; mcount[i]=0; }

    // p.clear();
    int msize =0, x;
    for(int i = 1; i<=n; i++){
        if(!isvisited[i]){
            // p.clear();
            msize = dfs_visit(i,1);
             /*
            for(int j=0; j<p.size(); j++){
                x = p[j]; 
                mcount[x] = msize;
            }
            msize = 0;*/
            //p.clear();
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
    cin>>n>>m;
    g = new vector<int>[n+1];
    isvisited = new bool[n+1];
    mcount = new int[n+1];
    int k, x, u,v;
    
    for(int i=0; i<m; i++){
        cin>>k;

        for(int j=0; j<k; j++){
            cin>>x;
            mcount[j]=x;
        }
        for(int i1=0; i1<k; i1++){
            for(int j=0; j<k; j++){
                if(i1!=j){
                    u = mcount[i1]; v = mcount[j];
                    g[u].push_back(v);
                }
            }
        }
    }

    dfs();

    for(int i=1; i<=n; i++){
        cout<<mcount[i]<<" ";
    }cout<<"\n";

    if(!g)delete[] g;
    if(!isvisited)delete[] isvisited;
    if(!mcount)delete[] mcount;
    return 0;
}
