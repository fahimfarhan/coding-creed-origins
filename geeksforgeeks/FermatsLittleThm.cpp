#include <bits/stdc++.h>

using namespace std;

#define MOD 17
int inv(int a){
    int ret = 1;
    for(int i=0; i<MOD-2; i++){
        ret = (ret*a)%MOD;  // original version. Too slow :'( 
    }
    return ret;
}

int Inv(int a) {
    int r = 1, t = a, k = MOD - 2;
    while (k) {
        if (k & 1) r = (long long) r * t % MOD;
        t = (long long) t * t % MOD;
        k >>= 1;
    }
    return r;
}

int main(){
    /**
     *    a^(p-1) mod p == 1 
     * => a^(p-2) mod p == a^(-1)
     * 
    */for(int i=1; i<100; i++){
        cout<<inv(i)<<" "<<Inv(i)<<"\n";
    }

    return 0;
}