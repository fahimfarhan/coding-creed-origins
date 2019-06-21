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

#define MAXN 100000

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
    int N = 3*MAXN+1;

    deque<ll> a; 
    ll res[3*MAXN+1][2];

    int n,q ;
    ll x;

    cin>>n>>q;

    for(int i=0; i<n; i++){
        cin>>x;
        a.push_back(x);
    }

    ll A,B;
    
    A = a.front();
    a.pop_front();

    for(int i=0; i<N; i++){
        
        B = a.front();
        a.pop_front();

        res[(i+1)][0] = A; res[(i+1)][1] = B;

        if(A>B){   a.push_back(B);    }
        else{
            swap(A,B);
            a.push_back(B);
        }
    }

    // cin>>n>>q;
    int in;
    while(q--){
        cin>>in;
        cout<<res[in][0]<<" "<<res[in][1]<<"\n";
    }

    return 0;
}
