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

    int n, a[1501], q, l, r, x;
    int N = 0; // initial inversion count
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
        for(int j=0; j<i; j++){
            if(a[j]>a[i]){
                N++;
            }
        }
    }
    N = N&1;

    cin>>q;
    while(q--){
        cin>>l>>r;
        x = r - l;
        x = (x*(x+1))>>1;
        N = N+x;
        N = N&1;
        if(N){  cout<<"odd\n";  }
        else{   cout<<"even\n"; }    
    }

    return 0;
}

