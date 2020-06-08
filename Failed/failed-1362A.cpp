/* Author : Qazi Fahim Farhan (@fahimfarhan) */
/* May the CodeForces be with you! */

#include <iostream>
#include <climits>  // this includes INT_MIN, INT_MAX, ... ...
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

int getMinimus(ll input) {
    int kount = 0;
    int n = input;
    while(n >= 8) {
        kount++;
        n = n >> 3;
    }

    while(n >= 4) {
        kount++;
        n = n >> 2;
    }

    while(n >= 2) {
        kount++;
        n = n >> 1;
    }

    return kount;
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
    ---------- Interactive problems ---------

    on each interactive questions' end, add `cout.flush()`
    say, cout<<"some weirdo question";
    cout<<"\n"; // end of question
    cout.flush(); // <-- just like this

    if still confusing, check out 1363D.cpp
    */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    ll a, b;
    ll d, r;
    cin>>T;
    while(T--) {
        cin>>a>>b;
        if(a < b) { swap(a,b);  }
        int kount = -1;
        if( (a % b) == 0) {
            d = a / b;
            kount = getMinimus(d);
        }
        cout<<kount<<"\n";
    }

    return 0;
}

