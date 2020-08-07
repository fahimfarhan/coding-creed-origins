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
// #include <unordered_set>
// #include <map>
// #include <unordered_map>
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

    int T, N, kount = 0, currentMaximus;
    int *v;

    cin>>T;
    for(int t = 1; t<=T; t++) {
        cin>>N;
        kount = 0;
        currentMaximus = INT_MIN;
        v = new int[N+2];
        v[0] = 0; v[N+1] = 0;
        for(int i=1; i<=N; i++) {    cin>>v[i];     }
        
        if(N == 1) {
            kount = 1;
        }else{
            for(int i=1; i<=N; i++) {
                if( (v[i] > v[i-1]) && (v[i] > v[i+1]) && (v[i] > currentMaximus)) {
                    kount++;
                    currentMaximus = v[i];
                }
            }
        }

        cout<<"Case #"<<t<<": "<<kount<<"\n";
        
        delete[] v;
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