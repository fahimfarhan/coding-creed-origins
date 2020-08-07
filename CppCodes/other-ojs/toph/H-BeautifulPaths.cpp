#ifdef _WIN32

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>

#else

#include <bits/stdc++.h>

#endif

using namespace std;

#define PI 2*acos(0)

typedef long long int ll;
// #define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MODULO = 1e9+7;

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


// int n,m;s
vector<int> *g;
vector<int> path;
bool *v, *isvisited;

int n,m, mycount;

void dfs_visit(int u){
    isvisited[u] = true;
    path.push_back(u);

    int w = 0;
    for(int i=0; i<g[u].size(); i++){
        w = g[u][i];
        if( (!isvisited[w]) && (v[w]==1) ){
            dfs_visit(w);
        }
    }
}

void dfs(){
    int temp=0;
    for(int i=1; i<=n;i++){
        if( (!isvisited[i]) && (v[i]==1) ){
            path.clear();
            dfs_visit(i);
            temp = path.size();
            temp = 1<<temp;
            temp--;
            mycount+=temp;
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
    isvisited = new bool[n+1];
    v = new bool[n+1];

    for(int i=0; i<=n; i++){    isvisited[i] = 0; }
    for(int i=1; i<=n; i++){    cin>>v[i]; }

    int a,b;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    mycount = 0;
    dfs();
    cout<<mycount<<"\n";

    return 0;
}
