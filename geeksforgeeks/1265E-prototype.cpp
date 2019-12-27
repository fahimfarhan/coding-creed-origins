#include <bits/stdc++.h>

using namespace std;

#define MOD 998244353

int inv(int a){
    int ret = 1;
    for(int i=0; i<MOD-2; i++){
        ret = (ret*a)%MOD;
    }
    return ret;
}


int main(){
    int n, *p;
    cin>>n;
    p = new int[n+1];
    for(int i=0; i<n; i++){
        cin>>p[i];
    }

    for(int i=0; i<n; i++){
        p[i] = inv(p[i]);
    }

    int e = 1+p[0];
    for(int i=1; i<n-1; i++){
        e = (e*p[i]+1)%MOD;
    }
    e = (e*p[n-1])%MOD;

    cout<<e<<"\n";

    return 0;
}