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

    ll n, m;
    pair<ll,ll> *a;

    cin>>n;
    a = new pair<ll,ll>[n+1];

    for(int i=0; i<n; i++){ cin>>m; a[i].first = m; a[i].second = (i+1);  }

    if(n<=3){
        cout<<a[0].second<<"\n";
    }else{
        sort(a,a+n);

        // for(int i=0; i<n; i++){     cout<<a[i].first<<" "<<a[i].second<<"\n";   }

        ll a0 = a[0].first;
        ll diff = a[1].first - a[0].first;

        vector<int> v;

        int i_prev=1;

        for(int i=2; i<n; i++){
            if( (a[i].first - a[i-1].first) != diff ){
                // save i
                v.push_back(i);
                i++;
            }else{
                i_prev = i;
            }
        }

        if(v.size() == 0){  cout<<"1\n";  exit(0);    }
        else if(v.size() == 1){ 
            int x = v[0]; 
            x = a[x].second;
            cout<<x<<"\n";
            exit(0);
        }

        v.clear();

        diff = a[2].first - a[1].first;

        i_prev=0;
        for(int i=1; i<n; i++){
            if( (a[i].first - a[i_prev].first) != diff ){
                // save i
                v.push_back(i);
                i++;
            }else{
                i_prev = i;
            }
        }

        if(v.size() == 0){  cout<<"1\n";  exit(0);    }
        else if(v.size() == 1){ 
            int x = v[0]; 
            x = a[x].second;
            cout<<x<<"\n";
            exit(0);
        }

        cout<<"-1\n";

    }
    

    delete[] a;

    return 0;
}
