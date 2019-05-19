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


// int n,m;
//vector<int> *g;
bool **isvisited;

int n,m,k,s, s_k;
string *g;

int x[4] = {-1,1,0,0};
int y[4] = {0,0,-1,1};

bool isvalid(int i, int j){
    if( (i>=0 && i<n) && (j>=0 && j<m) ){   return true;    }
    return false;
}

void dfs_visit(int i, int j){
    isvisited[i][j] = true;
    // g[i][j]='X';
    s_k = s_k-1;
    //cout<<s_k<<"\n";
    if(s_k<=0){ return; }
    int u=0,v=0;
    for(int i1=0; i1<4; i1++){
        u = i+x[i1];
        v = j+y[i1];
        if(isvalid(u,v)){
            if( (!isvisited[u][v]) && (g[u][v] == '.') ){
                dfs_visit(u,v);
                if(s_k <=0 ){   return; }
            }
        }
    }

}

void dfs(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if( (!isvisited[i][j]) && (g[i][j]=='.') ){
                dfs_visit(i,j);
                if(s_k <=0 ){   return; }
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

    cin>>n>>m>>k;

    g = new string[n+1];
    isvisited = new bool*[n+1];
    for(int i=0; i<=n; i++){    isvisited[i] = new bool[m+1];   }
    for(int i=0; i<n; i++){     cin>>g[i];    }

    s = 0;
    for(int i=0; i<n; i++){ 
        for(int j=0; j<m; j++){ 
            isvisited[i][j] = false;
            if(g[i][j] == '.'){ s++; }
        }
    }
    //cout<<s<<" "<<k<<"\n";
    s_k = s-k;

    dfs();
    for(int i=0; i<n; i++){
        // cout<<g[i]<<"\n";
        for(int j=0; j<m; j++){
            if( (!isvisited[i][j]) && (g[i][j]=='.')){   g[i][j]='X';    }
        }
    }

    for(int i=0; i<n; i++){
        cout<<g[i]<<"\n";
    }

    delete[] g;
    for(int i=0; i<n; i++){
        if(!isvisited[i])delete[] isvisited[i];
    }delete[] isvisited;
    return 0;
}
