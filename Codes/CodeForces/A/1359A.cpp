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

    ll T, n,m,k;
    ll r, result, m1, m2;

    cin>>T;


    while(T--) {
        cin>>n>>m>>k;
        r = n / k;
        if( (r >= m) || (m == 0) ) {
            result = m;
        }else{
            m1 = r;
            m2 = m - m1;

            double d = 1.0*m2 / (k - 1);

            result = m1 - d;

            // cout<<m<<" "<<m1<<" "<<m2<<" "<<r<<" "<<d<<"\n"; 
        }
        cout<<result<<"\n";
    }

    return 0;
}



