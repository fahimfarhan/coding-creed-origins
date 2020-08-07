/* Author : Qazi Fahim Farhan (@fahimfarhan) */
/* May the CodeForces be with you! */

#include <iostream>
// #include <sstream>
// #include <cstdio>
// #include <cmath>
// #include <cstring>
// #include <cctype>
// #include <string>
#include <vector>
// #include <list>
// #include <set>
// #include <map>
// #include <queue>
// #include <stack>
// #include <algorithm>
// #include <functional>
#include <iomanip>      // std::setprecision


using namespace std;

#define PI 2*acos(0)

//typedef long long int ll;
 #define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MOD = 1e9+7;

// int n,m;s
vector<int> *g;
bool *isvisited;

ll f(const ll &l,const ll &r,const ll &k,const ll &n){
    // cerr<<l<<" "<<r<<" "<<k<<" "<<n<<"\n";
    ll ret = 0, m = 0;
    m = (l+r);
    if( (m&1) == 1){    m = (m>>1) + 1;     }
    else{  m = m>>1;   }
    
    if(m == k){    return n;   }
    ll l1 = m+1, r1 = m-1, p = n-1;
    if(k<m){
        ret = f(l, r1, k, p );
    }else if(k>m){
        ret = f( l1 , r, k, p );
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    /* code */
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    /*
    std::cout << std::fixed;
    std::cout << std::setprecision(10);
    cout << num1 << endl;
    */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n,k, sz = 1;
    
    cin>>n>>k;
    for(int i=1; i<n; i++){    sz = 1 + (sz<<1);       }

    ll ret = f(1,sz,k,n);

    cout<<ret<<"\n";
    return 0;
}

