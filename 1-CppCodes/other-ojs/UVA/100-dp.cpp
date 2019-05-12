#include <bits/stdc++.h>

using namespace std;

int N = 900000;
int dp[900000];

int f(int x){
    int a,t,r;
    a = x;
    if(a>=N){
        if(a==1){   return 1; }
        else if( (a&1) == 1){
            t = 3*a+1;


        }else{
            t = a/2;
        }
        r = f(t)+1;
        return r;
    }else{
        if(dp[a]!=-1){  return dp[a];   }
        else if( (a&1) == 1){
        t = 3*a+1;
        }else{
            t = a/2;
        }
        r = 1+f(t);
        dp[a] = r;
        return dp[a];

    }
    

}

int main()
{
    for(int i=0; i<N; i++){    dp[i]=-1;    }
    dp[1] = 1;
    int i,j,k,l,ans=INT_MIN,temp;
    while(cin>>i>>j){
        ans=INT_MIN;
        k = min(i,j); l = max(i,j);
        for(int m=k; m<=l; m++){
            temp = f(m);
            ans = max(ans,temp);
        }
        cout<<i<<" "<<j<<" "<<ans<<"\n";
    }

    return 0;
}