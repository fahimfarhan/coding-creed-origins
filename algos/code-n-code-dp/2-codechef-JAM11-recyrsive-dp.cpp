#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int mod=1e9+7; 
ll dp[100010]; // 100000

inline ll getCount(const int& n) {
  if(dp[n]!=-1) {
    return dp[n];
  }

  dp[n] = ( getCount((n-1)) + getCount((n-2)) + getCount((n-3)) ) % mod;
  return dp[n];
}

inline void preprocess() {
  memset(dp, (-1), sizeof(dp));
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 4;

  getCount(100000);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  preprocess();
  int T, N;
  cin>>T;
  while(T--) {
    cin>>N;
    cout<<getCount(N)<<"\n";
  }

  return 0;
}