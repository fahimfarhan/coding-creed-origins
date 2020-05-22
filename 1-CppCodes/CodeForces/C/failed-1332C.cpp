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

int **dp;
int T, n, k;
string s;

int differ(int u, int v){
    int ret = 0;
    int maximus = 0;

    for(int i=0; i<26; i++){
        ret = ret + dp[u][i]+dp[v][i];
        maximus = max(maximus, dp[u][i]+dp[v][i]);
    }

    ret = ret - maximus;
    return ret;
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
    while(T--){
        cin>>n>>k;
        cin>>s;

        dp = new int*[k+1];
        for(int i=0; i<k; i++){    dp[i] = new int[27];    }

        for(int i=0; i<n; i++){
            for(int j=0; j<26; j++){
                dp[i][j] = 0;
            }
        }

        for(int i=0; i<n; i++){
            int i1 = i%k;
            int j1 = s[i] = 'a';

            dp[i1][j1]++;
        }

        int result = 0;
        for(int i=0; i<n; i++){
            result = result + differ(i, k-i-1);
        }

        cout<<(result>>1)<<"\n";

        for(int i=0; i<k; i++){    delete[] dp[i];    }
        delete[] dp;
    }

    return 0;
}

