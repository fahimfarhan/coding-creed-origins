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

    int T, n, x, oddKount, evenKount, backToBackNumKount;
    vector<int> a;
    bool b;
    cin>>T;
    while(T--) {
        cin>>n;
        for(int i=0; i<n; i++) {
            cin>>x;
            a.push_back(x);
        }

        sort(a.begin(),a.end());
        oddKount = 0; evenKount = 0; backToBackNumKount = 0;

        for(int i=1; i<n; i++) {
            if(a[i] - a[i-1] == 1) {
                backToBackNumKount++;
                a[i] = -1;
                a[i-1] = -1;
            }
        }

        for(int i=0; i<n; i++) {
            if(a[i] != -1) {    
                if( (a[i]&1) == 1) {    oddKount++; }
                else{   evenKount++;    }
            }
        }

        if( ((evenKount&1) == 1) && ((oddKount&1) == 1) && (backToBackNumKount>0) ) {
            b = true;
        }else if(((evenKount&1) == 0) && ((oddKount&1) == 0)){
            b = true;
        }else{
            b = false;
        }
        if(b) { cout<<"YES\n";  }
        else{   cout<<"NO\n";   }
        a.clear();
    }

    return 0;
}

