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

    int T;
    string s;
    int largestConsecutiveZero, largestConsecutiveOne;
    int zeroKount = 0;
    int oneKount = 0;
    while(T--) {
        cin>>s;
        largestConsecutiveOne = 0;
        largestConsecutiveZero = 0;
        zeroKount= 0;
        oneKount = 0;

        int temp0, temp1;
        int n = s.size();
        for(int i=0; i<n; i++) {
            if(s[i] == '0'){    zeroKount++; }
            else{   oneKount++;    } 
        }


    }


    return 0;
}

