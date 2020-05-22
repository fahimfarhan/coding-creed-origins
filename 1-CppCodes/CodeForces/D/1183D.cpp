#ifdef _WIN32

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>

#else

#include <bits/stdc++.h>

#endif

using namespace std;

#define PI 2*acos(0)

typedef long long int ll;
// #define ll long long int
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
    cout << setprecision(8);
    cout << num1 << endl;
    */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll q, n,a;
    cin>>q;
    while(q--){
        map<ll,ll> mp;
        vector<ll> s;

        cin>>n;
        for(int i=0; i<n; i++){ cin>>a; mp[a]++; }

        for(map<ll,ll>::iterator it = mp.begin(); it!=mp.end(); it++){
            a = it->second;
            s.push_back(a);
        }
        sort(s.begin(), s.end());
        a = 0;
        ll curr = s[s.size()-1];
        a+=curr;
        for(int i=s.size()-2; i>=0; i--){
            if(curr <= s[i] ){ curr--; }
            else{   curr=s[i]; }
            if(curr<=0){    break; }
            a+=curr;
        }

        cout<<a<<"\n";
    }

    return 0;
}
