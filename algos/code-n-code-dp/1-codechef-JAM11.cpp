#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define SIZE 100010
long long int dp[SIZE] = {0};  // int dp[] niyechilam, ejonno kaj kortisilo na! ll nile kaj kore!

inline void preprocessIterative() {
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = dp[1] + 1;
  dp[3] = dp[1] + dp[2] + 1;

  for(int i=4; i<SIZE; i++) {
    dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % MOD;
  }
}


inline void preprocessRecursive() {}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int T, N;

  preprocessIterative();

  cin>>T;
  while(T--) {
    cin>>N;
    // cout<<getCountRecursive(N)<<"\n";
    cout<< (dp[N] % MOD) <<"\n";
  }

  return 0;
}