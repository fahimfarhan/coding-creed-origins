#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


char **a;
int n,m;
// int n,m;
vector<int> *g;
bool *isvisited;
vector< pair<int,int> > dotPosition;

void dfs_visit(int u, int v, char ch){
    a[u][v]=ch;
    char nextCh = 'W';
    if(ch == nextCh){   nextCh = 'B'; }

    if(a[u+1][v]=='.'){ dfs_visit(u+1,v,nextCh); }
    if(a[u-1][v]=='.'){ dfs_visit(u-1,v,nextCh); }
    if(a[u][v+1]=='.'){ dfs_visit(u,v+1,nextCh); }
    if(a[u][v-1]=='.'){ dfs_visit(u,v-1,nextCh); }
}

void dfs(){
    int u=0,v=0;
    for(int i=0; i<dotPosition.size(); i++){
        u = dotPosition[i].first; v = dotPosition[i].second;
        if(a[u][v]=='.'){
            dfs_visit(u,v, 'W');
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
    a = new char*[n+2]; 
    for(int i=0; i<n+2; i++){   a[i]=new char[m+2]; }

    for(int i=0; i<n+2; i++){
        for(int j=0; j<m+2; j++){   a[i][j]='X'; }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){   cin>>a[i][j]; if(a[i][j]=='.'){  dotPosition.push_back({i,j}); } }
    }

    dfs();
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){   
            cout<<a[i][j];
        }cout<<"\n";
    }
    return 0;
}
