#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


int T,n,m;
vector<int> *g;
bool *isvisited;
int maximus;
ll *A;

void dfs_visit(int u, int prevDifference, int pathSize){
    //cout<<u<<"\n";
    isvisited[u]=true;
    int v = 0, nextPathSize = pathSize+1, nextDifference=0;
    maximus = max(maximus, pathSize);

    for(int i=0; i<g[u].size(); i++){
        v = g[u][i];
        nextDifference = A[v] - A[u];
        if( (!isvisited[v]) && (nextDifference>prevDifference) ){
            dfs_visit(v, nextDifference, nextPathSize);
        }
    }


}

void dfs(){
    for(int i=1; i<=n; i++){    isvisited[i] = false;   }
    for(int i=1; i<=n; i++){
        if(!isvisited[i]){
            dfs_visit(i,0,1);
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

    cin>>T;
    while(T--){
        cin>>n>>m;
        g = new vector<int>[n+1];
        isvisited = new bool[n+1];
        A = new ll[n+1];
        for(int i=1; i<=n; i++){    cin>>A[i]; }

        int a,b; 

        for(int i=0; i<m; i++){
            cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        /*
        for(int i=0; i<=n; i++){
            cout<<i<<"-->";
            for(int j=0; j<g[i].size(); j++)
            { cout<<g[i][j]<<" "; }cout<<"\n";
        }*/
        maximus = 0;
        dfs();
        cout<<maximus<<"\n";

        delete[] g;
        delete[] isvisited;
        delete[] A;
    }
    return 0;
}
