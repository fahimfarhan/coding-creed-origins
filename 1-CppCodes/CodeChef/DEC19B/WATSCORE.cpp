#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int main(){
    ll T, N, p, s, sum;
    cin>>T;
    while(T--){
        cin>>N;
        ll a[12] = {0};
        for(int i=0; i<N; i++){
            cin>>p>>s;
            a[p] = max(a[p],s);
        }
        sum = 0;
        for(int i=1; i<9; i++){    sum+=a[i];  }
        cout<<sum<<"\n";

    }
    return 0;
}