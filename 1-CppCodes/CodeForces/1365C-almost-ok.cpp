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
#include <map>
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

    ll T, n, x, maximus, *a, *b;
    map<ll,ll> mp;
    // cin>>T;
    // while(T--) {
        maximus = INT_MIN;
        cin>>n;
        a = new ll[n+1];
        b = new ll[n+1];

        for(int i=1; i<=n; i++) {
            cin>>x;
            a[x] = i;
        }

        for(int i=1; i<=n; i++) {
            cin>>x;
            b[x] = i;
        }

        ll dx = 0;
        ll shiftAmount = 0;
        for(int i=1; i<=n; i++) {
            dx = a[i] - b[i];
            if(dx < 0) {    dx = n + dx;    }
            mp[dx]++;
            if(mp[dx] > maximus) {
                maximus = mp[dx];
                shiftAmount = dx;
            }
            // maximus = max(maximus,mp[dx]);
        }
        // cout<<maximus<<"\n";
        // cout<<shiftAmount<<"\n";
        // todo: right shift b
        int j = 0;
        int kount = 0;
        for(int i=1; i<=n; i++) {
            j = i - shiftAmount;
            if(j < 1) { j = n - j; }

            if(a[j] == b[i]) {  kount++;    } 

        }
        cout<<kount<<"\n";
        // for(int i=1; i<=n; i++) {   cout<<b[i]<<" ";   }

        mp.clear();
    // }


    return 0;
}

/*
---------- Interactive problems ---------

    on each interactive questions' end, add `cout.flush()`
    say, cout<<"some weirdo question";
    cout<<"\n"; // end of question
    cout.flush(); // <-- just like this

    if still confusing, check out 1363D.cpp
    
*/