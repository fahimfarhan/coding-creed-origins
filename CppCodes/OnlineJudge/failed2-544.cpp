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
#include <map>
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
ll MOD = 1e9+7;

int n,m, src, dest, maximus, minimus;
vector<pair<int,int> > *g;
bool *isvisited;

map<string, int> mp;

void dfs(int u){
    cout<<"dfs 1\n";
    isvisited[u] = true;
    int v = 0, w = 0;
    for(int i=0; i<g[u].size(); i++){
        v = g[u][i].first;
        w = g[w][i].second;
        minimus = min(minimus, w);
        if(v == dest){
            maximus = max(maximus, minimus);
            return;
        }
        if(!isvisited[v]){
            dfs(v);
        }
    }
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

    int t = 0;
    while(true){
        cin>>n>>m;
        cout<<"here 00\n";
        if((n==0) && (m==0)){   break;  }
        t++;
        cout<<"here 01\n";
        isvisited = new bool[n+1];
        for(int i=0; i<n; i++){ isvisited[i] = false;   }
    cout<<"here 02\n";
        g = new vector<pair<int,int> >[n+1];
cout<<"here 03\n";
        mp.clear();        
cout<<"here 0\n";
        int kount = 0, w = 0;
        string su, sv;

        int u, v;
        for(int i=0; i<m; i++){
            cin>>su>>sv>>w;
            if(!mp[su]){    mp[su] = kount; u = kount; kount++;     }
            if(!mp[sv]){    mp[sv] = kount; v = kount; kount++;     }

            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }

        cin>>su>>sv;
        src = mp[su]; dest = mp[sv];
        cout<<"here .1\n";
        minimus =  1000000;
        maximus = -1000000;
        cout<<"here 1\n";
        dfs(src);
        cout<<"here 2\n";

        cout<<"Scenario #"<<t<<"\n";
        cout<<maximus<<" tons\n";
        cout<<"\n";

        if(!isvisited) delete[] isvisited;
        if(!g) delete[] g;
    }





    return 0;
}

