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

// int n,m;
vector<int> *g;
bool *isvisited;

#define TOTAL_MINUTES 24*60

bool doesIntersect(pair<int,int> p1, pair<int,int> p2){
    int s1,e1,s2,e2;
    s1 = p1.first; e1 = p1.second;
    s2 = p2.first; e2 = p2.second;

    if( (e1<= s2) || (e2 <= s1) ){  return false; }
    return true;
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

    int T, N, s,e;
    vector< pair<int,int> > v;
    map< pair<int,int>,char> mp;

    cin>>T;
    int m[TOTAL_MINUTES+10];

    bool isPossible = true;
    for(int t=1; t<=T; t++) {
        for(int i=0; i<=TOTAL_MINUTES; i++){ m[i] = 0; }
        isPossible = true;
        cin>>N;
        for(int i=0; i<N; i++){
            cin>>s>>e;
            v.push_back({s,e});
            for(int j=s; j<e; j++){ m[j]++; if(m[j]>=3){    isPossible = false; } }
        }

        if(!isPossible){
            cout<<"Case #"<<t<<": IMPOSSIBLE\n";
        }else{
            g = new vector<int>[N+1];

            for(int i=0; i<N; i++){
                for(int j=i+1; j<N; j++){
                    if(doesIntersect(v[i], v[j])) {
                        g[i].push_back(j);
                        g[j].push_back(i);
                    }
                }
            }

            string x;
            for(int i=0; i<N; i++){ x=x+"A";    }
            for(int i=0; i<N; i++){
                if(x[i]=='A') {
                    x[i] = 'J';
                    for(int j=0; j<g[i].size(); j++){
                        int pos = g[i][j];
                        x[pos] = 'C';
                    }
                }
            }

            cout<<"Case #"<<t<<": "<<x<<"\n";

            delete[] g;
        }
    }



    return 0;
}

