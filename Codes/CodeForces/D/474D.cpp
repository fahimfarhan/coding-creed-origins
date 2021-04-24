#include <bits/stdc++.h>

using namespace std;

inline int getCount1(const int& n) {
  // if( (n == 0) || (n == 1)) {  return 1; }
  if(n == 0) {  return 1; }

  // white
  int w = getCount1( (n-1) );
  // red
  int r = getCount1( (n-1) );
  return (w+r);
}


inline int getCount2(const int& n, const int& k) {
  if(n == 0) {
    return 1;
  }

  // W
  int w = 0;
  if(n >= k) {
    w = getCount2((n-k), k);
  }

  // R
  int r = getCount2((n-1), k);

  return (w+r);
}

inline void solve2() {
  int T, k;
  cin>>T>>k;

  int a, b, ans;
  while(T--) {
    cin>>a>>b;
    ans = 0;
    for(int i=a; i<=b; i++) {
      ans += getCount2(i, k); 
    }
    cout<<ans<<"\n";
  }
}

#define ll long long int
#define MOD 1000000007
int *dp;
ll *cumulativeFreq;
// int dp[100];

inline int getCount(const int& n, const int& k) {
  // if(n == 0) {
  //   return 1;
  // }

  if(dp[n] != -1) { return dp[n]; }

  // W
  int w = 0;
  if(n >= k) {
    if(dp[(n-k)] == -1) {
      dp[(n-k)] = getCount((n-k), k);
    }
    w = dp[(n-k)];
  }

  // R
  int r = 0;
  if(dp[ (n-1) ] == -1) {
    dp[n-1] = getCount((n-1), k);
  }

  r = dp[(n-1)];

  dp[n] = (w + r) % MOD;

  return dp[n];
}


inline void preprocess(const int& n, const int& k) {
  dp = new int[n+1];
  cumulativeFreq = new ll[n+1];

  int sizeOfDp = sizeof(dp[0]) * (n+1);
  memset(dp, -1, sizeOfDp);

  dp[0] = 1;
  for(int i=n; i>=1; i--) {
    getCount(i, k);
  }

  cumulativeFreq[0] = dp[0];
  for(int i=1; i<=n; i++) {
    cumulativeFreq[i] = ( (cumulativeFreq[(i-1)] % MOD) + (dp[i]%MOD) ) % MOD;
  }
}

inline void destructor() {
  if(!dp) {
    delete[] dp;
  }
  if(!cumulativeFreq) {
    delete[] cumulativeFreq;
  }
}


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  // solve2();
  int T, k, a, b, ans;
  cin>>T>>k;
  preprocess(100000, k);

  while(T--) {
    cin>>a>>b;
    ans = cumulativeFreq[b] - cumulativeFreq[(a-1)];
    if(ans < 0) {  // <-- this is the real culprit!
      ans = (ans + MOD);
    }
    cout<<ans<<"\n";
  }

  // for(int i=0; i<=100000; i++) {
  //   if(cumulativeFreq[i] < 0) {
  //     cout<<i<<" "<<cumulativeFreq[i]<<"\n";
  //   }
  // }


  destructor();
  return 0;
}