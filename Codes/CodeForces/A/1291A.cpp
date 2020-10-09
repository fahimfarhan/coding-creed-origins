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

    int t, n, size;
    string s;
    int pos[2];
    vector<int> v;
    cin>>t;
    while(t--){
        cin>>n;
        cin>>s;

        size = s.size();
        
        for(int i=0; i<size; i++){
            int m = s[i] - '0';
            if( (m&1) == 1){
                v.push_back(i);
            }
        }
        // for(int i=0; i<v.size(); i++){
        //     cout<<v[i]<<" ";
        // }
        if(v.size()<2){    cout<<"-1\n";   }
        else{
            for(int i=v[0]; i<=v[1]; i++){
                cout<<s[i]<<"";
            }cout<<"\n";
        }
        v.clear();
    }
    return 0;
}

