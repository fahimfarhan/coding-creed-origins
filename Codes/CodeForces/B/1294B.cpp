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
#include <algorithm>
// #include <functional>
#include <iomanip>      // std::setprecision


using namespace std;

#define PI 2*acos(0)

//typedef long long int ll;
 #define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MOD = 1e9+7;

// int n,m;
vector<int> *g;
bool *isvisited;

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

    int t, n, a, b;
    cin>>t;
    vector<pair<int,int> > v;
    while(t--){
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>a>>b;
            v.push_back({a,b});
        }
        sort(v.begin(), v.end());

        // for(int i=0; i<n; i++){
        //     cout<<v[i].first<<" "<<v[i].second<<"\n";
        // }cout<<"\n----------\n";

        pair<int, int> curr = {0,0};
        string path = "";
        bool b = true;
        int r, u;
        for(int i=0; i<n; i++){
            r = v[i].first - curr.first;
            u = v[i].second - curr.second;

            if(r<0 || u<0){
                b = false;
                break;
            }else{
                // 1st e r hobe, cz lexicographically smallest condition deya
                for(int j=0; j<r; j++){    path += "R";    } 
                for(int j=0; j<u; j++){    path += "U";    }
                curr = v[i];
            }
        }

        if(b){
            cout<<"YES\n";
            cout<<path<<"\n";
        }else{
            cout<<"NO\n";
        }

        v.clear();
    }

    return 0;
}

