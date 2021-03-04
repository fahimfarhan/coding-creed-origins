#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define N 10000
#define ll long long int

int fact[N];
int invFact[N];

int powr(int base, int power) {
  if(power == 0) return 1;
  if(power == 1) return base;

  int p = power >> 1;
  int result = powr(base, p);
  result = (result * 1ll * result) % MOD;
  ll one = 1;
  if( (power & one) == one) {
   result = (result * 1ll * base) % MOD;  
  }
  result = result % MOD;
  return result;
}

inline int inv(int input) {
  int p = MOD - 2;
  int output = powr(input, p);
  return output;
}

inline void preprocess() {
  fact[0] = 1;
  fact[1] = 1;
  for(int i=2; i<N; i++) {
    fact[i] = (fact[i-1] * 1ll * i) % MOD;
  }

  for(int i=0; i<N; i++) {
    invFact[i] = inv(fact[i]);
  }
}

inline int nCr(int n, int r) {
  if(r > n) return 0;
  int ncr = (fact[n] * 1ll * invFact[r]) % MOD;
  ncr = (ncr * 1ll * invFact[n-r]) % MOD;
  return ncr;
}

int main() {
  preprocess();
  int q, n, r;
  cin>>q;
  while(q--) {
    cin>>n>>r;
    cout<<nCr(n,r)<<"\n";
  }
  return 0;
}