/* SPDX-License-Identifier: MIT */
/* Copyright (c) 2020 Qazi Fahim Farhan (@fahimfarhan) */
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

void start() {}

ll conquer(ll *a,ll *swapSpace, int l, int r) {
    ll swapKount = 0;
    int size = r - l + 1;

    int mid = (l + r) / 2;

    int i1 = l; int j1 = mid+1; int k1 = 0;

    swapKount = 0;
    while( (i1 <= mid) && (j1 <= r) ){
        if(a[i1] < a[j1]) {
            swapSpace[k1] = a[i1];
            i1++; 
        }else{
            swapSpace[k1] = a[j1];
            // swapKount = swapKount + (j1 - k1);
            swapKount = swapKount + ((mid - i1) + 1);
            j1++; 
        }
        k1++;
    }
    while(i1<=mid) {
        swapSpace[k1] = a[i1]; i1++; k1++; 
    }

    while(j1<=r) {
        swapSpace[k1] = a[j1]; j1++; k1++;
    }

    for(int i=l; i<=r; i++) {
        a[i] = swapSpace[i - l];
    }
    return swapKount;
}

ll divide(ll *array, ll * swapSpace, int l, int r) {
    if(r<l) {   return 0; }
    if(r-l+1 == 1) {    return 0; }
    int mid = (l+r) / 2;
    ll kount1 = divide(array, swapSpace,  l, mid);
    ll kount2 = divide(array, swapSpace, mid+1, r);
    ll kount3 = conquer(array, swapSpace, l, r);
    ll kount = kount1 + kount2 + kount3;
    return kount;
}

ll ultraquicksort(ll *inputArray, ll *swapSpace, int l, int r) {
    return divide(inputArray, swapSpace, l, r);
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

    ll N, *a, *b;
    while(true) {
        cin>>N;
        if(N==0) {  break;  }
        a = new ll[N+1];
        b = new ll[N+1];
        for(int i=0; i<N; i++) {    cin>>a[i];  }

        cout<<ultraquicksort(a, b, 0, (N-1))<<"\n";

        // for(int i=0; i<N; i++) {
        //     cerr<<a[i]<<" ";
        // }cerr<<"\n";
        delete[] b;
        delete[] a;
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
