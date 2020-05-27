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

#define N 10005
ll dp[N][N];

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

    ll T, x1, y1, x2,y2,dx,dy;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if( (i == 0) || (j == 0) ){ dp[i][j] = 1;   }
            else{   dp[i][j] = dp[i-1][j] + dp[i][j-1]; }
        }
    }
    cin>>T;
    while(T--) {
        cin>>x1>>y1>>x2>>y2;
        dx = x2 - x1;
        dy = y2 - y1;

        if(dy > dx) {
            swap(dx,dy);
        }
        cout<<dp[dx][dy]<<"\n";
    }

    return 0;
}

