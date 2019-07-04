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

typedef  long long int ll;
// #define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MODULO = 1e9+7;

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


// int n,m;s
vector<int> *g;
bool *isvisited;

ll T,N,K,x; 
int64_t result;
queue<ll> a,b;
string s;

ll mypow(int p){
    ll ret = 1;
    if(p == 0){ return ret; }
    if(p == 1){ ret = (ret<<p); return ret ; }

    ll left, right;
    if( (p&1) == 1){    right = 2; }
    else {  right = 1;  }
    p = p>>1;
    left = mypow(p);
    ret = right;
    ret = ret*((left*left)%MODULO);
    ret = ret%MODULO;

    return ret;
}

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

    ll bitPos = log2(MODULO);
    // cerr<<bitPos<<"\n";

    cin>>T;
    for(int t = 1; t<=T; t++){


        result = 0;
        cin>>N>>K;
        
        cin>>s;

        ll acount=0, bcount=0;

        for(int i=0; i<N;i++ ){
            //cin>>ch;
            if(s[i] == 'A'){ acount++;  a.push( (i+1) ); }
            else{  bcount++;  b.push((i+1)); }
            if(bcount > acount+K){
                x = bcount - K; 
                for(int j=0; j<x; j++){
                    //ll temp = b.front(); b.pop();
                    //temp = mypow(temp);
                    //result = (result+temp)%MODULO;
                    ll temp = b.front(); b.pop();
                     temp = (1<<temp)%MODULO;
                    if(temp>MODULO){    temp = temp%MODULO;  }
                    result = (result+temp)%MODULO;
                }
                bcount = b.size();       
            }
        }

        //for(int i=0; i<a.size(); i++){  cout<<a[i]<<" ";   }cout<<"\n";
        //for(int i=0; i<b.size(); i++){  cout<<b[i]<<" ";   }cout<<"\n";
        /*
        x = b.size() - K;

        if(x<=0){   result = 0; }
        else{
            for(int i=0; i<x; i++){
                //int64_t temp = (1<<b[i]);
                //if(temp>MODULO){    temp = temp%MODULO;  }
                 //result = (result+temp)%MODULO;
                ll temp = b[i];
                temp = mypow(temp);
                result = (result+temp)%MODULO;
               
            }
        }*/
        cout<<"Case #"<<t<<": "<<result<<"\n";

        while(!a.empty()){  a.pop(); }
        while(!b.empty()){  b.pop(); }
        //a.clear();
        //b.clear();
    }

    return 0;
}