#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);
void dfs(int u);
void dfs_visit();

// int n,m;
vector<int> *g;
int n, *x,*y;
vector< pair<int,int> > nodes;
bool *isvisited;
int connectedComponent=0;

void dfs_visit(){
    for(int i=0; i<n; i++){
        if(!isvisited[i]){
            connectedComponent++;
            dfs(i);
        }
    }
}

void dfs(int u){
    isvisited[u] = true;
    for(int v=0; v<n; v++){
        if(!isvisited[v]){
            if( (x[v]==x[u]) || (y[v]==y[u]) ){
                dfs(v);
            }
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
    x = new int[n+1];
    y = new int[n+1];
    isvisited = new bool[n+1];
    isvisited[n] = false;
    //int a,b;
    for(int i=0; i<n; i++){
        cin>>x[i]>>y[i]; isvisited[i] = false;
    }

    dfs_visit();
    int ans = connectedComponent-1;
    cout<<ans<<"\n";

    delete[] x; delete[] y; delete[] isvisited;
    return 0;
}
