#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {

    ll T, n,m,x;

    cin>>T;
    while(T--) {
        cin>>n>>x>>m;
        ll l = x, r = x;
        for(int i=0; i<m; i++) {
            ll a,b;
            cin>>a>>b;
            if( (a<=r) && (b>=l) ) {
                l = min(l, a);
                r = max(r,b);
            }
        }
            cout<<(r - l + 1)<<"\n";
    }

    return 0;
}