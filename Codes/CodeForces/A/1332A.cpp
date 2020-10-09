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

    ll T, a, b, c, d, x, y, x1, y1, x2, y2;
    ll v1, v2;
    cin>>T;

    while(T--){
        cin>>a>>b>>c>>d;
        cin>>x>>y>>x1>>y1>>x2>>y2;

        if(x1>x2){  swap(x1, x2);   }
        if(y1 > y2){    swap(y1, y2); }

        a = -a;
        c = -c;

        v1 = a+b;
        v2 = c+d;
        x = x + v1;
        y = y + v2;
        
        if( (x1==x2) && ( a!=0 || b!=0 )){
            cout<<"No\n";
        }else if( (y1==y2) && (c!=0 || d!=0) ){
            cout<<"No\n";
        }
        else if( (x1<=x) && (x<=x2) && (y1<=y) && (y<=y2) ){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }
    }

    return 0;
}

