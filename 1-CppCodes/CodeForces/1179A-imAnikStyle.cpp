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

    ll *f, *s;
    ll n,q,x;
    deque<ll> a;

    cin>>n>>q;
    f = new ll[n+10]; s = new ll[n+10];

    for(int i=0; i<n; i++){ cin>>x; a.push_back(x); }

    ll A, B;
    A = a.front(); a.pop_front(); 

    for(int i=1; i<=n; i++){
        B = a.front(); a.pop_front();
        f[i] = A; s[i] = B; 
        if(A>B){    a.push_back(B); }
        else{
            swap(A,B);
            a.push_back(B);
        }
    }
    a.push_front(A);

    ll index;
    while(q--){
        cin>>index;
        if(index<=n){
            cout<<f[index]<<" "<<s[index]<<"\n";
        }else{
            index = index - n -1;
            index = index%(n-1)+1;

            B = a[index];
            cout<<A<<" "<<B<<"\n";
        }
    }

    return 0;
}
