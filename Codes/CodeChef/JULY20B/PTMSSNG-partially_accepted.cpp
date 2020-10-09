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

    ll T, N, a, b;
    ll *x, *y;
    ll one = 1;

    cin>>T;
    while(T--) {
        cin>>N;
        N = 4*N - 1;
        x = new ll[N];
        y = new ll[N];
        for(int i=0; i<N; i++) {
            cin>>x[i]>>y[i];
        }

        sort(x,x+N);
        sort(y,y+N);

        ll kurrentNumber, sum;
        kurrentNumber = x[0];
        sum = 1;
        for(int i=1; i<N; i++) {
            if(x[i] == kurrentNumber) {
                sum++;
            }else{
                if( (sum&one) == one) { a = kurrentNumber; break;   }
                else{   
                    kurrentNumber = x[i];
                    sum = 1;
                }
            }
        }

        kurrentNumber = y[0];
        sum = 1;
        for(int i=1; i<N; i++) {
            if(y[i] == kurrentNumber) {
                sum++;
            }else{
                if( (sum&one) == one) { b = kurrentNumber; break;   }
                else{   
                    kurrentNumber = y[i];
                    sum = 1;
                }
            }
        }

        cout<<a<<" "<<b<<"\n";

        delete[] x;
        delete[] y;
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