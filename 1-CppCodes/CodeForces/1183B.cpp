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

    ll q, n, k, a, amin, amax;

    cin>>q;
    while(q--){
        cin>>n>>k;
        amin = INT_MAX; amax = INT_MIN;
        for(int i=0; i<n; i++){ cin>>a; amin = min(a,amin); amax = max(a,amax);  }

        if( ( (-k+amin) > (k+amax) ) || ( (k+amin) < (-k+amax) ) ){
            cout<<"-1\n";
        }else{
            a = min( (k+amax),(k+amin) );
            cout<<a<<"\n";
        }

    }



    return 0;
}
