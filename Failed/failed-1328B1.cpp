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

    int T, n, sum, j, k;
    cin>>T;
    while(T--){
        cin>>n>>k;

        string s(n,'a');
        sum = 0;
        for(int i=1; i<n; i++){
            sum+=i;
            if(sum >= k){    sum-=i; break; }            
            j = i;
        }
        // s[j] = 'b';
        // s[k - sum] = 'b';
        int pos1 = n-j;
        int pos2 = n - (k-sum);

        pos1 = pos1 - 1;
        pos2 = pos2 - 1;

        s[pos1] = 'b';
        s[pos2] = 'b';

        cout<<s<<"\n";
    }

    return 0;
}
//  original
// aaabb
// aabab
// baaba
// bbaaa
// abb
// bab
// aaaaabaaaaabaaaaaaaa
