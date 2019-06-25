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

    map<ll,ll> mp_plus, mp_minus;

    ll count,p,m, n, x, y;

    cin>>n;
    //x = new ll[n+1];
    //y = new ll[n+1];

    for(int i=1; i<=n; i++){    cin>>x>>y; p = x+y; m = x-y; mp_plus[p]++; mp_minus[m]++;     }


    count = 0;

    // map<ll,ll>::iterator it;
    for(map<ll,ll>::iterator it = mp_plus.begin(); it!= mp_plus.end(); it++){
        x = it->second;
        x = x*(x-1);
        x = x>>1;
        count+=x;
    }

    for(map<ll,ll>::iterator it = mp_minus.begin(); it!= mp_minus.end(); it++){
        x = it->second;
        x = x*(x-1);
        x = x>>1;
        count+=x;
    }
    

    cout<<count<<"\n";

    //delete[] y;
    //delete[] x;

    return 0;
}
