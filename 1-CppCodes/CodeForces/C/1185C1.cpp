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

int n,m, *a;

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
    cin>>n>>m;
    a = new int[n+1];

    for(int i=0; i<n; i++){     cin>>a[i];    }

    int t = 0, res = 0;
    int j=0,l=0;
    for(int i=0; i<n; i++){
        t+=a[i];
        sort(a,a+i);
        res = 0;
        if(t>m){
            j = t;
            l = i-1;
            while(j>m){ j-=a[l]; l--; res++; }
        }

        cout<<res<<" ";
    }cout<<"\n";

    delete[] a;
    return 0;
}
