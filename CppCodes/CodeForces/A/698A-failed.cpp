#include <bits/stdc++.h>

using namespace std;

#define ll long long int

ll max3(ll x, ll y, ll z){
    return max(max(x,y),z);
}

int main(){
    ll n, maximus = INT_MIN, prev = 0;
    cin>>n;
    int a[n+1] = {0};
    ll dp[n+1][3] = {0};

    for(int i=1;i<=n; i++){  cin>>a[i];  }
    // init / base case
    dp[0][0] = 0; dp[0][1] = 0; dp[0][2] = 0;
    // dp
    prev = 0;
    for(int i=1; i<=n; i++){
        if(a[i] == 0){  dp[i][0] = max3(dp[(i-1)][0],dp[(i-1)][1],dp[(i-1)][2]); }
        else if(a[i] == 1){ dp[i][1]  = 1+max(dp[(i-1)][0], dp[(i-1)][2]);      }
        else if(a[i] == 2){ dp[i][2]  = 1+max(dp[(i-1)][0], dp[(i-1)][1]);      }
        else {
            if(prev == 1)        dp[i][1]  = 1+max(dp[(i-1)][0], dp[(i-1)][2]);
            else if(prev == 2)   dp[i][2]  = 1+max(dp[(i-1)][0], dp[(i-1)][1]);
        }
        prev = a[i];
    }

    maximus = max3(dp[n][0], dp[n][1], dp[n][2]);
    ll minimus = 0;
    minimus = n-maximus;

    cout<<minimus<<"\n";

    return 0;
}