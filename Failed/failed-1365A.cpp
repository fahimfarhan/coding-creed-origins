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

    ll T, n,m, x;
    // int **a;
    int *row, *col;
    
    cin>>T;
    while(T--) {
        cin>>n>>m;
        // a = new int*[n+1];
        // for(int i=0; i<=n; i++) {   a[i] = new int[m+1];    }
    
        row = new int[n+1];
        col = new int[m+1];
        for(int i=0; i<=n;i++ ) {  row[i] = 0;  }
        for(int i=0; i<=m; i++) {   col[i] = 0; }

        for(int i = 0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cin>>x;
                if(x == 1) {    row[i] = 1; col[j] = 0; }
            }
        }

        int rowZeroKount = 0;
        int colZeroKount = 0;

        for(int i=0; i<n; i++) {    if(row[i] == 0) rowZeroKount++; }
        for(int i=0; i<m; i++) {    if(col[i] == 0) colZeroKount++; }

        int minimus = min(rowZeroKount, colZeroKount);

        if(minimus & 1 == 1) {
            cout<<"Ashish\n";
        }else{
            cout<<"Vivek\n";
        }

        delete[] row;
        delete[] col;
        // for(int i=0; i<=n; i++) {   delete[] a[i];  }
        // delete[] a;
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