/* Author : Qazi Fahim Farhan (@fahimfarhan) */
/* May the CodeForces be with you! */

#include <iostream>
// #include <sstream>
// #include <cstdio>
#include <cmath>
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


void foo(ll n, ll d) {
        ll m = n;
        for(int i=d; i>=1; i--) {
            if( (n%d) == 0) {
                m = n/d;
                break;
            }
        }
        cout<<m<<"\n";       
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

    ll T, n, k, d;
    cin>>T;
    while(T--) {
        cin>>n>>k;
        if(n <= k) {
            cout<<1<<"\n";
        }else{
            d = sqrt(n)+1;
            if(d < k) {
                d+=1;
            }else{
                d = k;
            }

            foo(n,d);
        }



    }

    return 0;
}

