#include <bits/stdc++.h>

#define MOD 1000000007
#define ll long long int

using namespace std;

ll dp[1000] = {0};

inline void preprocess() {
  dp[1] = 1;
  dp[2] = 2;

  for(int i=3; i<1000; i++) {
    dp[i] = (dp[i-1] + dp[i-2]) % MOD;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  preprocess();
  
  int T, N;
  cin>>T;
  while(T--) {
    cin>>N;
    cout<<dp[N]<<"\n";
  }

  return 0;
}