/* Author : Qazi Fahim Farhan (@fahimfarhan) */
/* May the CodeForces be with you! */

#include <iostream>
// #include <sstream>
// #include <cstdio>
#include <cmath>
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

    int T, n, x, evenKount, oddKount;
    int *a; 
    bool b = true;
    cin>>T;
    while(T--) {
        cin>>n>>x;
        a = new int[n+1];
        for(int i=0; i<n; i++) {    cin>>a[i]; }
        evenKount = 0; oddKount = 0;

        for(int i=0; i<n; i++) {
            if( (a[i] & 1) == 1){  oddKount++; }
            else{   evenKount++;    }
        }
        b = true;
        if(oddKount == 0) { b = false;  }
        else if(oddKount >= x && ( (x&1) == 1) ){    b = true;    }
        else{
            // cout<<"ok ek = "<<oddKount<<" "<<evenKount<<"\n";
            int y = oddKount;
            if( (oddKount&1) == 0 ){    y-=1; }
            int z = x - y;
            if(z <= evenKount) {    b = true;   }
            else{   b = false;  }
            // cout<<"x y z = "<<x<<y<<z<<"\n";
        }
        

        if(b){  cout<<"Yes\n";  }
        else{   cout<<"No\n";   }
        delete[] a;
    }


    return 0;
}

