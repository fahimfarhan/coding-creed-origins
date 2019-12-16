#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main(){
    ll n, m, *a, **dp;
    cin>>n>>m;
    if(n>m){    cout<<"YES\n";  }
    else{
        a = new ll[n+1];
        dp = new ll*[n+1];

        for(int i=0; i<=n; i++){
            dp[i] = new ll[m+1];
        }
        cerr<<"ok1\n";
        for(int i=1; i<=n; i++){ cin>>a[i];  }
        cerr<<"ok2\n";
        ll tempRemainder = 0;
        for(int i=1; i<=n; i++){
            tempRemainder = a[i]%m;
            for(int j=1; j<=m; i++){
                dp[i][ (tempRemainder + j)%m ] = dp[i-1][ (tempRemainder+j)%m ] | dp[i-1][ j ];
            }
            dp[i][tempRemainder] = 1;
        }

        if(dp[n][0]){   cout<<"YES\n";  }
        else{   cout<<"NO\n";   }

    }
    return 0;
}