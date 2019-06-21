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

int n,M, *a, *cf;

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

    cin>>n>>M;

    a = new int[n+1];
    cf = new int[n+1];
    cf[0] = 0;
    for(int i=1; i<=n; i++){     cin>>a[i]; cf[i] = cf[i-1]+a[i];    }

    int t=0, j=0, res=0, temp=0;
    for(int i=1; i<=n; i++){
        t = cf[i];
        if(t<=M){   cout<<"0 "; }
        else{
            sort(a+1, a+i+1);
            j = i-1;
            res = 0;
            while(t>M){
                t -= a[j];
                j--;
                res++; 
            }

            cout<<(res)<<" ";
        }
    }cout<<"\n";

    delete[] cf;
    delete[] a;

    return 0;
}
