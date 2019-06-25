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

    ll T,N,M, *C, Di, Fi, Bi, count, cf;
    vector<ll> b;

    cin>>T;

    while(T--){
        cin>>N>>M;
        C = new ll[M+1];

        C[0] = 0; cf = 0;
        for(int i=1; i<=M; i++){    cin>>C[i]; cf+=C[i];  }

        count = 0;
        for(int i=0; i<N; i++){
            cin>>Di>>Fi>>Bi;

            if(C[Di]>0){    count+=Fi; C[Di]--; cf--; }
            else{  b.push_back( (-Bi)); }
        }

        if(b.size() > cf ){
            sort(b.begin(), b.end());
        }

        ll minimus = min(cf, (ll)b.size());

        for(int i=0; i<minimus; i++){
            count-=b[i];
        }

        cout<<count<<"\n";


        delete[] C;
    }

    return 0;
}
