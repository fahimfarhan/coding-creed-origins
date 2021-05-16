#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define double long double
int mod=1e9+7; 
     
int a[100010];

inline void preprocess() {
  a[0] = 0; a[1] = 1; a[2] = 2; a[3] = 4;

  for(int i=4; i<100010; i++) {
    a[i] = (a[i-1] + a[i-2] + a[i-3]) % mod;
  }
}
     
int32_t main(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);  
 

 // precalc();
 preprocess();

  int M = 100000;
  int kount = 0;

 for(int t=10000; t<M; t++) {
      int n=0;
      // cin>>n;
      n = t;
      vector<int>dp(n+1);
      if(n==1)cout<<1<<'\n';
      else if(n==2)cout<<2<<'\n';
      else if(n==3)cout<<4<<'\n';
      else{
      dp[0]=0,dp[1]=1,dp[2]=2,dp[3]=4;
      for(int i=4;i<=n;i++){
          dp[i]=(dp[i-1]+dp[i-2]+dp[i-3])%mod;
      }

      int expectedOutput = dp[n]%mod;
      int actualOutput = a[n];
        if(a[n] !=dp[n]) {
          cout<<n<<" "<<dp[n]<<" "<<a[n]<<"\n";
          kount++;
        }
      }
  }

  cout<<"-------\n\nerror = "<<kount<<" correct = "<<(M-kount)<<"\n";
 
 
 // cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
  return 0;
}