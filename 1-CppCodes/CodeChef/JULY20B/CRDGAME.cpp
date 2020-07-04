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

ll calcPower(ll n) {
    ll ret = 0;
    while(n > 0) {
        ret = ret + n%10;
        n = n / 10;
    }
    return ret;
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

    ll T, N, powerOfA, powerOfB, mortiScore, chefScore;
    ll A[105], B[105];

    cin>>T;
    while(T--) {
        cin>>N;
        
        chefScore = 0;
        mortiScore = 0;

        for(int i=0; i<N; i++) {
            cin>>A[i]>>B[i];
        }
        
        for(int i=0; i<N; i++) {
            // cin>>A>>B;
            powerOfA = calcPower(A[i]);
            powerOfB = calcPower(B[i]);

            if(powerOfA > powerOfB) {
                chefScore++;
            }else if(powerOfA < powerOfB) {
                mortiScore++;
            }else{
                chefScore++;
                mortiScore++;
            }
        }

        if(chefScore > mortiScore) {
            cout<<0<<" "<<chefScore<<"\n";
        }else if(mortiScore > chefScore) {
            cout<<1<<" "<<mortiScore<<"\n";
        }else{
            cout<<2<<" "<<chefScore<<"\n";
        }
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