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
#include <stack>
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
vector<int> *g;
stack<int> st;
bool *isvisited;

void dfs_visit(int u){
    isvisited[u] = true;
    int v = 0;
    for(int i=0; i<g[u].size(); i++){
        v = g[u][i];
        if(!isvisited[v]){
            dfs_visit(v);
        }
    }
    st.push(u);
}

void dfs(){
    for(int i=0; i<=n; i++){    isvisited[i] = false; }
    for(int i=1; i<=n; i++){
        if(!isvisited[i]){    dfs_visit(i);   }
    }
}

void printer(){
    int top = 0;
    while(!st.empty()){
        top = st.top();
        st.pop();
        cout<<top<<" ";
    }cout<<"\n";
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

    while(true){
        cin>>n>>m;
        if(n==0 && m==0){   exit(0);    }
        
        g = new vector<int>[n+1];
        isvisited = new bool[n+1];

        int a,b;
        for(int i=0; i<m; i++){
            cin>>a>>b;
            g[a].push_back(b);
        }

        dfs();
        printer();


        delete[] g;
        delete[] isvisited;
    }

    return 0;
}

