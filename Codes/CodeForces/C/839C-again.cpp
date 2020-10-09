#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


int n,m;
vector<int> *g;
bool *isvisited;


double dfs(int u){
    isvisited[u] = true;
    int k=0,v=0, len=0;    double E=0,x=0,X=0,p=0;
    len = g[u].size();
    // case 1: leaf 
    if(len == 0){   return 0;   }

    for(int i=0; i<len; i++){
        v = g[u][i];
        if(!isvisited[v]){
            k++;
            x = dfs(v);
            X+=x;
        }
    }

    if(k==0){   return 0;   }
    p = 1.0/k;
    E = 1 + p*X;
    return E;
}



int main(int argc, char const *argv[])
{
    /* code */
    /* Soln soln */
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
    g = new vector<int>[n+1];
    isvisited = new bool[n+1];

    for(int i=0; i<=n; i++){    isvisited[i] = false; }
    m=n-1;
    int a,b;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        g[a].push_back(b);
        // g[b].push_back(a);
    }

    cout << setprecision(8);
    cout<<dfs(1)<<"\n";

    if(!g)delete[] g;
    return 0;
}
/*
    int     -2147483648 2147483647
    short   -32768      32767
*/