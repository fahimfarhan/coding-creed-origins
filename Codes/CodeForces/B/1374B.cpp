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

bool isDivisibleBy3(const int& x) {
    int sum = 0;
    int n = x;
    while(n>0) {
        sum = sum + n%10;
        n = n / 10;
    }

    return ( (sum%3) == 0);
}

ll stepKount(ll x){
    ll n = x;
    ll kount = 0;
    ll one = 1;
    if(n == one) {    return 0;   }
    while(n != one) {
        if(!isDivisibleBy3(n)) {
            return -1;
        }else {
            if( (n & one) == one) {
                n = n<<1; // n*=2;
            }else{ 
                n = n / 6;
            }
            kount++;
        }
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
    */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll T, n, kount;
    cin>>T;

    while(T--) {
        cin>>n;
        kount = stepKount(n);
        cout<<kount<<"\n";

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