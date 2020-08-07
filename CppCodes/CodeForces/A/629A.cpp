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

    int n; string s;
    int *r, *c;

    cin>>n;
    r = new int[n+1]; c = new int[n+1];
    for(int i=0; i<=n; i++){    r[i] = 0; c[i] = 0; }

    for(int i=0; i<n; i++){
        cin>>s;
        
        for(int j=0; j<n; j++){
            if(s[j] == 'C'){
                r[i]++; c[j]++;
            }
        }
    }

    int res = 0;

    for(int i=0; i<n; i++){
        res+=(r[i]*(r[i]-1) + c[i]*(c[i]-1))>>1;
    }

    cout<<res<<"\n";

    delete[] c; delete[] r;

    return 0;
}
