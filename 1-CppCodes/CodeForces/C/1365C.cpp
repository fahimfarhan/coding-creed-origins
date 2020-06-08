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

    int n;
    cin>>n;
    int a[n+1],  b[n+1], indexOfA[n+1];

    for(int i=1; i<=n; i++) {
        cin>>a[i];
        indexOfA[a[i]] = i;
    }

    for(int i=1; i<=n; i++) {
        cin>>b[i];
    }

    map<int,int> mp;
    int j = 0;
    int dx = 0;
    for(int i=1; i<=n; i++) {
        j = indexOfA[b[i]];
        dx = i - j;
        if(dx < 1) {
            dx = n + dx;
        }

        mp[dx]++;
    }

    int maximus = INT_MIN;
    map<int,int>::iterator it;

    // it->first = shiftAmount i
    // it->second = kount (shiftAmount i koyta number er jonno call hoise)

    for(it = mp.begin(); it != mp.end(); it++) {
        maximus = max(maximus, it->second);
    }

    cout<<maximus<<"\n";


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