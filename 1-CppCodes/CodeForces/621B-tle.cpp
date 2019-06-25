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

    ll count,dx, dy, n, *x, *y;

    cin>>n;
    x = new ll[n+1];
    y = new ll[n+1];

    for(int i=1; i<=n; i++){    cin>>x[i]>>y[i];    }

    count = 0;
    for(int i=1; i<n; i++){
        for(int j=i+1; j<=n; j++){
            dx = abs(x[i]-x[j]);
            dy = abs(y[i]-y[j]);

            if(dx == dy){   count++; }
        }
    }

    cout<<count<<"\n";

    delete[] y;
    delete[] x;

    return 0;
}
