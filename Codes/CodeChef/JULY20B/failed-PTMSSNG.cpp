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
#include <unordered_map>
// #include <queue>
#include <stack>
#include <algorithm>
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

    ll T, N, x, y;
    stack<ll> sx, sy;
    unordered_map<ll,int> mpx, mpy;

    while(T--) {
        cin>>N;
        N = 4*N - 1;

        ll *a, *b;
        a = new ll[N];
        b = new ll[N];
        for(int i=0; i<N; i++) {
            // cin>>x>>y;
            // sx.push(x);
            // sy.push(y);
            cin>>a[i]>>b[i];
        }

        for(int i=0; i<N; i++) {
            x = a[i];   //sx.top(); sx.pop();
            y = b[i];   //sy.top(); sy.pop();

            if(mpx[x] == 1) {
                mpx[x] = 0;
            }else{
                mpx[x] = 1;
            }

            if(mpy[y] == 1) {
                mpy[y] = 0;
            }else{
                mpy[y] = 1;
            }
        }

        for(auto it:mpx) {
            if(it.second == 1) {
                x = it.first; break;
            }
        }

        for(auto it:mpy) {
            if(it.second == 1) {
                y = it.first; break;
            }
        }

        cout<<x<<" "<<y<<"\n";
        mpx.clear();
        mpy.clear();
        delete[] a;
        delete[] b;

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