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

    ll t, n,s,k, x;
    cin>>t;
    while(t--){
        cin>>n>>s>>k;
        ll a[n+1] = {0};
        for(int i=0; i<k; i++){
            cin>>x;
            a[x] = 1;
        }
        ll kount1 = 0, kount2 = 0;
        bool b1=false, b2=false;
        for(int i=s; i>0; i--){
            if(a[i] == 0){ b1 = true; break; }
            kount1++;
        }
        for(int i=s; i<=n; i++){
            if(a[i] == 0){ b2  = true; break; }
            kount2++;
        }
        ll res = 0;
        if(b1== true && b2==false){
            res = kount1;
        }else if(b2== true && b1==false){
            res = kount2;
        }else{
            res = min(kount1, kount2);
        }

        cout<<res<<"\n";
    }


    return 0;
}

