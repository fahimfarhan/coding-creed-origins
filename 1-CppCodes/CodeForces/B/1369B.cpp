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

    ll T;
    int n, zeroKount, oneKount, minimus;
    string s, t;
    cin>>T;
    while(T--) {
        cin>>n;
        cin>>s;
        zeroKount = 0; oneKount = 0;

        for(int i=0; i<n; i++) {
            if(s[i] == '0') { zeroKount++;    }
            else{   break; }
        }

        for(int i=n-1; i>=0; i--) {
            if(s[i] == '1') { oneKount++; }
            else{   break;  }
        }

        if(zeroKount + oneKount < n) {
            t = "";
            for(int i=0; i<=zeroKount; i++) {
                t= t + "0";
            }

            for(int i=0; i<oneKount; i++) {
                t = t + "1";
            }
        }else{
            t = s;
        }

        cout<<t<<"\n";

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