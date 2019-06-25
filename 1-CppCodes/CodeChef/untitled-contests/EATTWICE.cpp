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
bool *isvisited;

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

    ll T, N, M, Vi,Di, res;
    vector< pair<ll,ll> > v;
    cin>>T;

    while(T--){
        v.clear();
        res = 0;

        cin>>N>>M;
        for(int i=0; i<N; i++){
            cin>>Di>>Vi;
            v.push_back({Vi,Di});
        }

        sort(v.begin(), v.end());
        
        ll i,j;
        i = N-1;
        j = N-2;

        while(true){
            if(j<0){    break;  }
            if(v[i].second == v[j].second){ j--; }
            else{ break; }
        }

        res = v[i].first + v[j].first;
        cout<<res<<"\n";
        
    }



    return 0;
}
