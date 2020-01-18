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

    ll l,r, ret, pos, n, diff;
    ret = 0; pos = 0; n = 1;

    cin>>l>>r;

    diff = r-l;

    ret = 0;
    while(diff >= n){
        ret+=n;
        n=n<<1;
        pos++;
    }

    while( r >= n){
        ll temp = (l>>pos)^(r>>pos);
        if(temp&1 == 1){
            ret+=n;
        }
        n=n<<1;
        pos++;
    }
    cout<<ret<<"\n";
    return 0;
}

