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

ll T, n, *a, maximus = -1, maximusPos = 0;

bool solve(){
    cin>>n;
        a = new ll[n+1];
        maximus = -1;
        for(int i=0; i<n; i++){
            cin>>a[i];
            if(a[i]>maximus){
                maximus = a[i];
                maximusPos = i;
            }
        }

        bool b = true;
        for(int i=maximusPos-1; i>=0; i--){
            if(a[i]>=a[i+1]){
                a[i] = a[i+1]-1;
                if(a[i]<=0){ delete[] a; return false; }
            }
        }

        for(int i=maximusPos+1; i<n; i++){
            if(a[i]>=a[i-1]){
                a[i] = a[i-1]-1;
                if(a[i]<=0){ delete[] a; return false; }
            }
        }
        delete[] a;
        return true;
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

    cin>>T;
    while (T--){
        /* code */
        bool b = solve();
        if(b){  cout<<"Yes\n";  }
        else{   cout<<"No\n";   }
    }
    


    return 0;
}

