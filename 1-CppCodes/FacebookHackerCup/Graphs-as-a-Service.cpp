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
#define MY_INF 1000099
typedef long long int ll;
// #define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MODULO = 1e9+7;

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


// int n,m;s
int g[55][55];
// bool *isvisited;
vector< pair< pair<int,int>,int > > E;
int T, n,m;

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
    for(int t=1; t<=T; t++){
        //g = new int*[n+1];
        //for(int i=0; i<=n; i++){    g[i] = new int[n+1];    }

        for(int i=0; i<55; i++){
            for(int j=0; j<55; j++){    g[i][j]=MY_INF; }
        }
        // for(int i=0; i<=n; i++){    g[i][i]=0;  }

        cin>>n>>m;

        int a,b,w;
        
        for(int i=0; i<m; i++){
            cin>>a>>b>>w;
            E.push_back({{a,b},w});
            g[a][b] = w; 
            g[b][a] = w;
        }

        for(int k=1; k<=n; k++){
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    if(g[i][j] > (g[i][k]+g[k][j]) ){
                        g[i][j] = (g[i][k]+g[k][j]);
                        g[j][i] = g[i][j];
                    }
                }
            }
        }


        bool b123 = true;
        for(int i=0; i<m; i++){
            a = E[i].first.first;
            b = E[i].first.second;
            w = E[i].second;

            if(g[a][b] != w){   b123=false; break; }
        }

        cout<<"Case #"<<t<<": ";
        if(!b123){  cout<<"Impossible\n";   }
        else{
            cout<<m<<"\n";
            for(int i=0; i<m; i++){
                a = E[i].first.first;
                b = E[i].first.second;
                w = E[i].second;
                cout<<a<<" "<<b<<" "<<w<<"\n";
                
            }

        }

        cout<<"\n------------\n";
        for(int i=0; i<=n; i++){
            for(int j=0; j<=n; j++){
                cout<<g[i][j]<<" ";
            }cout<<"\n";
        }
        cout<<"\n------------\n";

        //for(int i=0; i<=n; i++){    delete[] g[i];  }
        //delete[] g;
    }

    return 0;
}
