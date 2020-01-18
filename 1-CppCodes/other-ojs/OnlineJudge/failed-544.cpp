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
ll INT_MAX = 1e9+7;


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

    int n = 0, m = 0, t = 0, w = 0, kount = 0;
    int minimus = 0;
    string u, v, src, dest;

    int g[201][201];


    while(true){
        cin>>n>>m;
        if( (n==0) && (m==0)){
            break;
        }else{ 
            for(int i=0; i<201; i++){
                for(int j=0; j<201; j++){
                    g[i][j] = 0;
                }
            }
            t++;
            map<string, int> mp;
            kount = 0;
            for(int i=0; i<m; i++){
                cin>>u>>v>>w;
                if(mp[u] == 0){ mp[u] = kount; kount++; }
                if(mp[v] == 0){ mp[v] = kount; kount++; }
                g[mp[u]][mp[v]] = w;
                g[mp[v]][mp[u]] = w;
            }

            cin>>src>>dest;

            // some graph algo
            // maybe fordfulkarson / floyed warshal idk
            for(int k=0; k<n; k++){
                for(int j=0; j<n; j++){
                    for(int i=0; i<n; i++){
                        // g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
                        g[i][j] = max( g[i][j], min(g[i][k],g[k][j]));
                        g[j][i] = g[i][j];
                    }
                }
            }

            minimus = g[mp[src]][mp[dest]];
            cout<<"Scenario #"<<t<<"\n";
            cout<<minimus<<" tons\n";
            cout<<"\n";

            mp.clear();

        }
    }


    return 0;
}

