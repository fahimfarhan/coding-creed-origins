/* Author : Qazi Fahim Farhan (@fahimfarhan) */
/* May the CodeForces be with you! */

#include <iostream>
// #include <sstream>
// #include <cstdio>
// #include <cmath>
// #include <cstring>
// #include <cctype>
// #include <string>
// #include <vector>
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

//typedef long long ll ll;
 #define ll long long int
// other popular ones=> ll64_t, ull64_t => use for 10^18

const ll MOD = 119 << 23 | 1;

ll inv(const ll &input){
    ll ret = 1;
    ll k = MOD - 2;
    ll a = input;
    while (k)
    {   /* code */
        if( (k&1) == 1){
            ret = ((ret * a) % MOD);
        }
        a = ((a*a) % MOD);
        k = k>>1;
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

    ll n;


    cin>>n;
    ll p, E;

    cin>>p;
    E = ((100 * inv(p) )%MOD);
        
    for(ll i=1; i<n; i++){
        cin>>p;
        p = ((100 * inv(p) )%MOD);
        E = (E+1)*p;
        E = E%MOD;
    }

    cout<<E<<"\n";

    return 0;
}

