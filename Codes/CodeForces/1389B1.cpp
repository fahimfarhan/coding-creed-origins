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
 #define ll int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MOD = 1e9+7;

// int n,m;
vector<int> *g;
bool *isvisited;

ll T, n, z, k, score, maximus;
ll *a, *cf;

void start() {}

ll rangedSum(int i, int j) {    return (cf[i] - cf[j-1]);     }

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

    cin>>T;

    while(T--) {

        cin>>n>>k>>z;
        a = new ll[n+2];
        cf = new ll[n+2];

        for(int i=1; i<=n; i++) {    cin>>a[i];  }
        
        a[0] = 0; a[n+1] = 0; cf[0] = 0; cf[n+1] = 0;
        for(int i=1; i<=n; i++) {    cf[i] = cf[i-1] + a[i];   }
        
        maximus = cf[k+1];  // silly mistake , base case: all numbers sequentially, so in 1 based indexing, `maximus = cf[i+1]`
        score = a[1];   // initial score

        for(int i=1; i<=k; i++) {   // <-- silly mistake `i = 2` chhilo. but `i = 1` hobe
            int used = i-1; 
            int remaining = k - used;
            score = cf[i];

            if(remaining <= 2*z) {
                int m = remaining/2;

                score = score + m * (a[i+1] + a[i]);

                if(2*m != remaining) {
                    score = score + a[i+1];
                }
            }else{
                score = score + z*(a[i+1] + a[i]);
                used+=2*z;
                remaining = k - used;

                int start = i+1;
                int end = start + remaining - 1; // cz formula, range = end - start + 1 => end = start + range - 1 

                score = score + rangedSum(end, start);
            }

            maximus = max(maximus , score);
        }
        
        cout<<maximus<<"\n";
        delete[] a;
        delete[] cf;
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

/*                                           When Panda is Life !
 
                              _,add8ba,
                            ,d888888888b,
                           d8888888888888b                        _,ad8ba,_
                          d888888888888888)                     ,d888888888b,
                          I8888888888888888 _________          ,8888888888888b
                __________`Y88888888888888P"""""""""""baaa,__ ,888888888888888,
            ,adP"""""""""""9888888888P""^                 ^""Y8888888888888888I
         ,a8"^           ,d888P"888P^                           ^"Y8888888888P'
       ,a8^            ,d8888'                                     ^Y8888888P'
      a88'           ,d8888P'                                        I88P"^
    ,d88'           d88888P'                                          "b,
   ,d88'           d888888'                                            `b,
  ,d88'           d888888I                                              `b,
  d88I           ,8888888'            ___                                `b,
 ,888'           d8888888          ,d88888b,              ____            `b,
 d888           ,8888888I         d88888888b,           ,d8888b,           `b
,8888           I8888888I        d8888888888I          ,88888888b           8,
I8888           88888888b       d88888888888'          8888888888b          8I
d8886           888888888       Y888888888P'           Y8888888888,        ,8b
88888b          I88888888b      `Y8888888^             `Y888888888I        d88,
Y88888b         `888888888b,      `""""^                `Y8888888P'       d888I
`888888b         88888888888b,                           `Y8888P^        d88888
 Y888888b       ,8888888888888ba,_          _______        `""^        ,d888888
 I8888888b,    ,888888888888888888ba,_     d88888888b               ,ad8888888I
 `888888888b,  I8888888888888888888888b,    ^"Y888P"^      ____.,ad88888888888I
  88888888888b,`888888888888888888888888b,     ""      ad888888888888888888888'
  8888888888888698888888888888888888888888b_,ad88ba,_,d88888888888888888888888
  88888888888888888888888888888888888888888b,`"""^ d8888888888888888888888888I
  8888888888888888888888888888888888888888888baaad888888888888888888888888888'
  Y8888888888888888888888888888888888888888888888888888888888888888888888888P
  I888888888888888888888888888888888888888888888P^  ^Y8888888888888888888888'
  `Y88888888888888888P88888888888888888888888888'     ^88888888888888888888I
   `Y8888888888888888 `8888888888888888888888888       8888888888888888888P'
    `Y888888888888888  `888888888888888888888888,     ,888888888888888888P'
     `Y88888888888888b  `88888888888888888888888I     I888888888888888888'
       "Y8888888888888b  `8888888888888888888888I     I88888888888888888'
         "Y88888888888P   `888888888888888888888b     d8888888888888888'
            ^""""""""^     `Y88888888888888888888,    888888888888888P'
                             "8888888888888888888b,   Y888888888888P^
                              `Y888888888888888888b   `Y8888888P"^
                                "Y8888888888888888P     `""""^
                                  `"YY88888888888P'
                                       ^""""""""'
  */
