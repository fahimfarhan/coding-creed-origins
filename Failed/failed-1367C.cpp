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
 #define ll int
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

    ll T, n, k, first, last, maximus;
    string s;

    cin>>T;
    while(T--) {
    vector<int> v;
        maximus = 0;
        cin>>n>>k;
        cin>>s;
        for(int i=0; i<n; i++) {
            if(s[i] == 1) {
                int j = i+1;
                v.push_back(j);
            }
        }

        int N = v.size();

        first = 0;
        if(v[0] != 1) {
            ll r = v[0];
            ll m = r - 1 - k;
            if(m >0) {
                first = m + (k - 1);
                first = first / (2*k);
            }
        }
        maximus += first;
        for(int i=1; i<N; i++){
            ll r = v[i];
            ll l = v[i-1];
            ll m = r - (l + 1 + 2*k);
            if(m > 0) {
                m = m + k-1;
                m = m / (2*k);
                maximus+=m;
            }
        }

        last = 0;
        if(v[N-1] != n ) {
            ll l = v[N-1];
            ll r = n;
            ll m = r - l - k;
            if(m > 0) {
                last = (m + k - 1) / 2*k;
            }
        }
        maximus += last;
        cout<<maximus<<"\n";
        maximus = 0;
    }


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