#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int main(){
    ll T, N, prev, diff, a;
    bool b = true;
    cin>>T;
    while(T--){
        prev = -6;
        b = true;
        cin>>N;
        for(ll i=0; i<N; i++) {
            cin>>a;
            if(a == 1) {
                diff = i - prev;
                if(diff < 6){   b = false; }
                prev=i;
            }
        }
        if(b){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
    return 0;
}