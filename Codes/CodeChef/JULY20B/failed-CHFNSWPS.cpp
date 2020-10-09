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
#include <set>
// #include <unordered_set>
#include <unordered_map>
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

    ll one = 1;
    ll T, N, x, swapKount, kount, *A, *B;
    bool b;
    unordered_map<ll,int> mpA, mpB;
    set<ll> myset;
    vector<ll> v;
    
    cin>>T;
    while(T--) {
        cin>>N;
        // A = new ll[N+1];
        // B = new ll[N+1];

        for(int i=0; i<N; i++) {
            cin>>x;
            mpA[x]++;
            myset.insert(x);
        }

        for(int i=0; i<N; i++) {
            cin>>x;
            mpB[x]++;
            myset.insert(x);
        }

        b = true;
        swapKount = 0;
        
        for(auto n : myset) {
            if( ((mpA[n] + mpB[n]) & one )  == one ) {  b = false; break; }
            ll temp = abs(mpA[n] - mpB[n]);
            if(temp > 0) {
                swapKount = swapKount + temp;
                v.push_back(n);
            }

        }

        if(!b) {    cout<<"-1\n";   }
        else{
            kount = 0;

            ll halfOfSwapKount = swapKount / 2;
            ll currentSwapKount = 0;
            sort(v.begin(), v.end());
            for(int i=0; i<v.size()/2; i++) {
                ll n = v[i];
                ll temp = abs(mpA[n] - mpB[n])/2;
                currentSwapKount += temp;
                kount = temp * n;

                if(currentSwapKount == halfOfSwapKount) { break;}
            }   
             cout<<kount<<"\n";
        }


        mpA.clear();
        mpB.clear();
        myset.clear();
        v.clear();
        // delete[] A;
        // delete[] B;
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