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

    int T, n,a,b, zeroKount, oneKount;
    vector<pair<int,int> > v;
    bool isPossible;

    cin>>T;
    while(T--) {
        isPossible = true;
        zeroKount = 0; oneKount = 0;
        cin>>n;

        for(int i=0; i<n; i++) {
            cin>>a;
            v.push_back({a,0});
        }

        for(int i=0; i<n; i++) {
            cin>>b;
            if(b == 1) {    oneKount++; }
            else{   zeroKount++;    }
            v[i].second = b;
        }

        if( (zeroKount == n) || (oneKount == n) ) {
            // check if already sorted
            a = v[0].first;
            for(int i=1; i<n; i++) {
                if(a > v[i].first ) {    isPossible = false; break;    }
                a = v[i].first;
            }
        }

        if(isPossible) {  cout<<"Yes\n";  }
        else{   cout<<"No\n";   }
        v.clear();

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