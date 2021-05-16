#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define double long double
int mod=1e9+7; 
     

     
int32_t main(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);  
 
  int t=0; 
  cin>>t;
 // precalc();
  while(t--){
      int n=0;
      cin>>n;
      vector<int>dp(n+1);
      if(n==1)cout<<1<<'\n';
      else if(n==2)cout<<2<<'\n';
      else if(n==3)cout<<4<<'\n';
      else{
      dp[0]=0,dp[1]=1,dp[2]=2,dp[3]=4;
      for(int i=4;i<=n;i++){
          dp[i]=(dp[i-1]+dp[i-2]+dp[i-3])%mod;
      }
      cout<<dp[n]%mod<<'\n';
      }
  }
 
 
 // cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
  return 0;
}