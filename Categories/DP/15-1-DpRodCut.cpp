#include <bits/stdc++.h>
using namespace std;

#define M_INF -9999
int p[] = {0,1,5,8,9,10,17,17,20,24,30};

int dp[11];
int memoizedCutRod(int n){
    for(int i=0; i<=n; i++){
        dp[i] = M_INF;
    }
    return 0;
}

int memoizedCutRodAux(int n){
    if(dp[n]>=0){   return dp[n]; }
    int q;
    if(n==0){
        q = 0;
    }else{
        q = M_INF;
        for(int i=1; i<=n; i++){
            q = max(q, p[i]+memoizedCutRodAux(n-i));
        }
    }
    return dp[n] = q;
}

void BottomUpCutRod(int n){
    dp[0] = 0;
    for(int j=1; j<=n; j++){
        int q = M_INF;
        for(int i=1; i<=j; i++){
            q =max(q, p[i]+dp[j-i]);
        }
        dp[j] = q;
    }
    //return dp[n];
}

int main()
{

    //memoizedCutRod(10);
    BottomUpCutRod(10);
    cout<<"\ndp2\n";
    for(int i=0; i<11; i++){
        cout<<dp[i]<<" ";
    }
    return 0;
}