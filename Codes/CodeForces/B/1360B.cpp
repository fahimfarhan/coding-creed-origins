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

    int T, n, a;
    vector<int> v;


    cin>>T;
    while(T--) {
        cin>>n;
        for(int i=0; i<n; i++) {
            cin>>a;
            v.push_back(a);
        }

        sort(v.begin(), v.end());

        int minimus = 99999;
        int dx;
        for(int i=1; i<n; i++) {
            dx = v[i] - v[i-1];
            minimus = min(minimus,dx);
        }
        cout<<minimus<<"\n";
        // if( (n&1) == 1) {
        //     int n1 = 99999;
        //     int n2 = 99999;

        //     int m = n/2;
            
        //     if( (m-1) >= 0 ) {
        //         n1 = v[m] - v[m-1];
        //     }
        //     if( (m+1) < n ) {
        //         n2 = v[m+1] - v[m];
        //     }

        //     int minimus = min(n2,n1);
        //     cout<<minimus<<"\n";
        // }else {
        //     int m = n/2;
        //     int minimus = v[m] - v[m-1];
        //     cout<<minimus<<"\n";
        // }

        v.clear();
    }
    return 0;
}

