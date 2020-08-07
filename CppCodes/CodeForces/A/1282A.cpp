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
ll MODULO = 1e9+7;

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


// int n,m;s
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

    ll T, a,b,c, r, c1, c2, ans;
    cin>>T;
    while(T--){
        cin>>a>>b>>c>>r;
        c1 = c-r; c2 = c+r;
        // c1 < c2
        // a  < b
        if(c1>c2){  swap(c1, c2);   }
        if(a>b){    swap(a,b);      }

        ans = 0;
        if( (b<c1) || (a>c2)){   ans = b-a; }
        else{
            if(a<c1){   ans = c1-a; }
            if(b>c2){   ans += (b-c2); }
        }
        cout<<ans<<"\n";
    }


    return 0;
}

