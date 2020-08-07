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

    ll T, N, *A, minimus;
    int *B;
    cin>>T;

    for(int t=1; t<=T; t++) {
        cin>>N;
        minimus = 0;
        A = new ll[N+1];
        B = new int[N+1];
        for(int i=0; i<N; i++)  {cin>>A[i];}
        B[0] = 0;
        for(int i=1; i<N; i++) {
            if(A[i] > A[i-1]) {
                B[i] = B[i-1] + 1;
            }else if(A[i] < A[i-1]) {
                B[i] = B[i-1]-1;
            }else{
                B[i] = B[i-1];
            }

            if(B[i] > 4) {
                B[i] = 0;
                minimus++;
            }else if(B[i] < 0) {
                B[i] = 4;
                minimus++;
            }
        }

        cout<<"Case #"<<t<<": "<<minimus<<"\n";
        delete[] B;
        delete[] A;
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