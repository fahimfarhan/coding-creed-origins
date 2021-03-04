#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007

inline ll power(ll base, ll p, ll mod) {
  ll result = 1;
  ll one = 1;
  while (p) {
    if((p&one) == one) {
      result = ((result%mod) * (base%mod))%mod;
      p--;
    }else{
      base = ((base%mod) * (base%mod))%mod;
      p = p >> 1;
    }
  }
  // result = result % mod;
  return result;
}

inline ll sum(ll A, ll B, ll N, ll mod) {
  ll result = (power(A, N, mod) + power(B, N, mod)) % mod;
  return result;
}

inline ll modularGcd(ll A, ll B, ll N) {
  if(A == B) {
    return sum(A,B,N,MOD); // (power(A, N, MOD) + power(B, N, MOD)) % MOD;
  }else{
    ll num = abs(A - B);
    ll maximus = 0; // maximus = maximum potential candidate
    for(ll i=1; i*i <= num; i++) {
      if( (num % i) == 0) {
        // i, num/i are potential candidates
        ll temp1 = sum(A, B, N, i);
        if(temp1==0) {
          maximus = max(maximus, i);
        }

        ll j = num/i;
        temp1 = sum(A,B,N,j);
        if(temp1==0) {
          maximus = max(maximus, j);
        }
      }
    }
    return maximus;
  }
}

int main() {
  ll T, N, A, B;
  cin>>T;
  while (T--) {
    cin>>A>>B>>N;
    ll maximus = modularGcd(A, B, N);
    maximus = maximus % MOD;
    cout<<maximus<<"\n";
  }
}
/*
371051719
2
*/