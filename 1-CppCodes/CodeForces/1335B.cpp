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

    ll T, a, b, n;
    string t = "";
    for(int i=0; i<26; i++){
        t = t+(char)(i+'a');
    } 
    cin>>T;
    while(T--){
        cin>>n>>a>>b;
        string s = "";

        string t1 = t.substr(0,b);
        for(int i=0; i< a-b; i++){
            t1 = t1 + t1[b-1];
        }
        // s = t1;
        
        // int j=0;
        // for(int i=b; i<n; i++){
        //     s = s+s[j]; j++;
        // }

        int d = n/a;
        int r = n%a;

        for(int i=0; i<d; i++){
            s = s + t1;
        }
        s = s + t1.substr(0,r);
        cout<<s<<"\n";
    }


    return 0;
}

