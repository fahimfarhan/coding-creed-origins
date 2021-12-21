#include <bits/stdc++.h>
using namespace std;

#define ll long long int

#define M 200001
#define MOD 1000000007

ll *dp;

inline void preprocess() {
  dp = new ll[M];
  for(int i=0; i<9; i++) {
    dp[i] = 2;
  }
  dp[9] = 3;
  for(int i=10; i<M; i++) {
    dp[i] = (dp[i-9] + dp[i-10])%MOD;
  }
}

inline ll f(ll n, const ll& m) {
  ll result = 0;
  while(n>0) {
    ll x = n % 10;
    if( (m+x) < 10) {
      result = result + 1;
    }else {
      result = result + dp[m + x - 10];
    }
    result = result % MOD;
    n = n / 10;
  }
  return result;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll n, m;
  ll result = 0;
  ll temp = 0;
  int T = 0;

  preprocess();

  cin>>T;
  while(T--) {
    cin>>n>>m;
    cout<<f(n, m)<<"\n";
  }
  delete[] dp;
  return 0;
}