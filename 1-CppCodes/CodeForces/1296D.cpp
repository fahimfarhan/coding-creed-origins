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

    ll n,a,b,k, result;
    ll *hp;
    ll r, d;

    cin>>n>>a>>b>>k;
    hp = new ll[n+1];

    for(int i=0; i<n; i++){
        cin>>hp[i];
    }

    for(int i=0; i<n; i++){
        hp[i] = hp[i]%(a+b);
        if(hp[i] == 0){
            hp[i] = a+b; // rewind 
        }
		hp[i] = ((hp[i] + a - 1) / a) - 1; // <-- ei line ta keno? o.O eta ceiling chay ni mone hocche... 
        // d = hp[i]/a;
        // r = hp[i]%a;
        // if(r){  d++;    }
        // hp[i] = d;
    }

    sort(hp,hp+n);

    result = 0;
    for(int i=0; i<n; i++){
        if(k-hp[i]<0){  break;  }
        result++;
        k-=hp[i];
    }
    
    cout<<result<<"\n";

    delete[] hp;
    return 0;
}

