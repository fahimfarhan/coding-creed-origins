/* Author : Qazi Fahim Farhan (@fahimfarhan) */
/* May the CodeForces be with you! */

#include <iostream>
// #include <sstream>
// #include <cstdio>
// #include <cmath>
// #include <cstring>
// #include <cctype>
// #include <string>
#include <vector>
// #include <list>
// #include <set>
// #include <map>
// #include <queue>
// #include <stack>
// #include <algorithm>
// #include <functional>
#include <iomanip>      // std::setprecision


using namespace std;

#define PI 2*acos(0)

//typedef long long int ll;
 #define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MODULO = 1e9+7;

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


int n,m;
int *g;
int *degree;
bool *isvisited;
int startOfPath, endOfPath;
vector<int> zeros;

int dfs(int i){
    cerr<<"dfs "<<i<<"\n";
    if(g[i]==0){    return i; }
    int x = g[i];
    return dfs(x);
}

int main(int argc, char const *argv[])
{
    /* code */
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    /*
    std::cout << std::fixed;
    std::cout << std::setprecision(10);
    cout << num1 << endl;
    */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
            cerr<<"ok 00"<<"\n";
    g = new int[n+1];
    degree = new int[n+1];

            cerr<<"ok 01"<<"\n";
    g[0] = 0;
    for(int i=0; i<=n; i++){    degree[i] = 0;  }
    for(int i=1; i<=n; i++){    
        cin>>g[i];
        if(g[i] != 0){
            degree[i]++;
            degree[g[i]]++;
        }
    }
            cerr<<"ok 0"<<"\n";

    for(int i=1; i<=n; i++){    if(g[i] == 0) zeros.push_back(i);   }
    
        cerr<<"ok1"<<"\n";
    
    for(int i=1; i<=n; i++){
        if(degree[i] == 1){
            startOfPath = i;
            endOfPath = dfs(i);
            cerr<<startOfPath<<" "<<endOfPath<<"\n";
            g[endOfPath] = startOfPath;

        }
    }

    if(zeros.size() == 0){ 
        for(int i=1; i<=n; i++){
            if(degree[i] == 1){
                startOfPath = i;
                endOfPath = dfs(i);
                g[endOfPath] = startOfPath;
            }
        }
    }else if(zeros.size() == 1){
        int x = zeros[0];
        
        for(int i=1; i<=n; i++){
            if(degree[i] == 1){
                startOfPath = i;
                endOfPath = dfs(i);
                if(x!=-1){
                    g[endOfPath] = x;
                    g[x] = startOfPath;
                    x = -1;
                }else{
                    g[endOfPath] = startOfPath;
                }

            }
        }
    }else{
            cerr<<"ok1"<<"\n";
        for(int i=1; i<=n; i++){
            if(degree[i] == 1){
                startOfPath = i;
                endOfPath = dfs(i);
                g[endOfPath] = startOfPath;
            }
        }
    
        int u, v;
                cerr<<"ok2"<<"\n";
        for(int i=0; i<zeros.size()-1; i++){
            u = zeros[i];
            v = zeros[i+1];
            g[u] = v;
        }
        cerr<<"ok3"<<"\n";
        u = zeros[zeros.size()-1];
        v = zeros[0];

        g[u] = v;
        cerr<<"ok4"<<"\n";
    }

    for(int i=1; i<=n; i++){    cout<<g[i]<<" ";    }
    cout<<"\n";

    delete[] g;
    delete[] degree;
    return 0;
}

