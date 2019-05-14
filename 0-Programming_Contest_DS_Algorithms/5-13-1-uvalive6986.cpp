#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    long long int m,n,t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        if(m==1){   cout<<1<<"\n";  }
        else{
            ll low = m-1;
            if(low == 1 ){  low=2;  }
            ll high = (m<<1) -1;
            high = min(high,n);
            ll ans = high - low +1;
            cout<<ans<<"\n";
        }
    }
    return 0;
}
