#include <bits/stdc++.h>

using namespace std;

#define MODULO 1e9+7
#define N 2005

    int n,k;
    int **dp;

void printer(){
    for(int i=0; i<=k; i++){
        for(int j=0; j<=n; j++)
        {    cout<<dp[i][j]<<" ";    }cout<<"\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

 

    cin>>n>>k;

    dp = new int*[k+1];
    for(int i=0; i<=k; i++){    dp[i]=new int[n+1];    }

    for(int i=0; i<=k; i++){
        for(int j=0; j<=n; j++){    dp[i][j]=0; }
    }

    for(int i=1; i<=n; i++){    dp[1][i]=1; }
    
    for(int i=2; i<=k; i++){
        for(int j=1; j<=n; j++){    
            for(int l=j; l<=n; l+=j){
                dp[i][l]=dp[i][l]+dp[i-1][j];
                if(dp[i][l]>MODULO){   dp[i][l]-=MODULO;  }                
            }
        }
    }

    int ans = 0; 

    for(int i=1; i<=n; i++){
        ans+=dp[k][i];
        if(ans>=MODULO){    ans-=MODULO;    }
    }

    cout<<ans<<"\n";

    cerr<<"----------------\n";
    printer();
    cerr<<"----------------\n";

    for(int i=0; i<=k; i++){    delete[] dp[i]; }
    delete[] dp;
    return 0;
}