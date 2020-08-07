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

// int n,m;
vector<int> *g;
bool *isvisited;

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

    const int MOD = 998244353;
    ll n, k, a, prev = -1;
    ll ans = 1, sum = 0;
    cin>>n>>k;

    sum = (k*((n<<1)-k+1))>>1; // silly me. Use ll NOT int 
    // looks like we got an overflow error, so we can only use Add operation
    // for(int i=n-k+1; i<=n; i++){    sum += i; }

    for(int i=0; i<n; i++){
        cin>>a;
        if( a >= (n-k+1) ){
            if(prev!=-1)
                ans = ans * (i-prev) % MOD;
            prev = i;
        }
    }
    cout<<sum<<" "<<ans<<"\n";
    return 0;
}

