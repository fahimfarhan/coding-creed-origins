/* Author : Qazi Fahim Farhan (@fahimfarhan) */
/* May the CodeForces be with you! */

#include <iostream>
#include <climits>
// #include <sstream>
// #include <cstdio>
#include <cmath>
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

    int T, n, zeroKount, oneKount, tempZero, tempOne;
    int costOf0011, costOf1100;
    int minimus = 0;
    
    string s;

    cin>>T;
    while(T--) {
        cin>>s;
        n = s.size();
        zeroKount = 0; oneKount = 0;
        tempZero = 0; tempOne = 0;
    
        for(int i=0; i<n; i++) {
            if( s[i] == '0' ) {     zeroKount++;    }
            else{   oneKount++;     }
        }

        costOf0011 = 0;
        costOf1100 = 0;
        minimus = INT_MAX;

        for(int i=0; i<n; i++) {
            if( s[i] == '0' ) {     tempZero++;    }
            else{   tempOne++;     }
            costOf0011 = tempOne + (zeroKount - tempZero);
            costOf1100 = tempZero + (oneKount - tempOne);
            minimus = min(minimus, costOf1100); 
            minimus = min(costOf0011, minimus); 
        }
        cout<<minimus<<"\n";
    }

    return 0;
}

