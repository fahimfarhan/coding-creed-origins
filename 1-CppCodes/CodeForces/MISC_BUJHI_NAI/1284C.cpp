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

    int n;
    ll m;
    cin>>n>>m;

    ll fact[n+1];
    fact[0] = 1;
    for(int i=1; i<=n; i++){
        fact[i] = (fact[i-1]*i)%m;
    }

    ll ret = 0, kountForNextPermutation = 0, segmentLength = 0;
    for(int i=1; i<=n; i++){
        segmentLength = n-i+1;
        kountForNextPermutation = segmentLength*( (fact[i]*fact[segmentLength])%m );
        ret = (ret+kountForNextPermutation)%m;
    }

    cout<<ret<<"\n";

    return 0;
}

