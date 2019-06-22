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

typedef int ll;
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

    int n,q;

    list<ll> a;

    cin>>n>>q;


    ll maximus=INT_MIN, maximusPos=0;
    ll x;
    for(int i=1; i<=n; i++){    cin>>x; a.push_back(x); if(x > maximus){  maximus = x; maximusPos = i; }  }

    ll zeroBasedIndex = maximusPos - 1;

    ll A,B;
    A = a.front();
    a.pop_front();

    vector<pair<ll,ll> > p;
    for(int i=0; i<zeroBasedIndex; i++){
        B = a.front();
        a.pop_front();

        p.push_back({A,B});

        if(A<B){ swap(A,B); }
        a.push_back(B);
    }

    vector<ll> v;

    while( !a.empty() ){  
        x = a.front(); a.pop_front(); v.push_back(x);
    }

    //cout<<maximus<<" "<<maximusPos<<"\n";
    //for(int i=0; i<v.size(); i++){ cout<<v[i]<<" "; }cout<<"\n";


    maximusPos--;
    
    long long int index = 0, len = v.size();
    while(q--){
        cin>>index;
        index=index-1;

        if(index<maximusPos){
            cout<<p[index].first<<" "<<p[index].second<<"\n";
        }
        else{
            index = (index-maximusPos)%len;
            cout<<A<<" "<<v[index]<<"\n";
        }
    }

    //delete[] a;

    return 0;
}
