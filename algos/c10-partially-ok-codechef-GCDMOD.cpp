#include <bits/stdc++.h>
#include <ios>
#include <iostream>

using namespace std;

#define ll long long int
#define MOD 1000000007

inline int modularPower(int base, ll power, int mod) {
  if(power == 0) {  return 1; }
  if(power == 1) {  return base % mod; }
  ll p = power >> 1;
  ll output = modularPower(base, p, mod);
  output = (output * output) % mod;
  if( (power & 1) == 1) {
    output = (output * (base%mod) ) % mod;
  }
  output = output % mod;
  return output;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll A,B,N,T;
  cin>>T;
  while(T--) {
    cin>>A>>B>>N;
    if(A == B) {
      ll gcd = modularPower(A, N, MOD) + modularPower(B, N, MOD);
      gcd = gcd % MOD;
      cout<<gcd<<"\n";
    }else{
      ll num = abs(A - B);
      ll maximus = 1;
      for(ll i=1; i*i <= num; i++) {
        if( (num % i) == 0) {
          ll temp = modularPower(A, N, i) + modularPower(B, N, i);
          temp = temp % i;

          if(temp == 0) { maximus = max(maximus, i);  }

          ll j = num / i;
          temp = modularPower(A, N, j) + modularPower(B, N, j);
          temp = temp % j;

          if(temp == 0) { maximus = max(maximus, j);  }
        }
      }
      maximus = maximus % MOD;
      cout<<maximus<<"\n";
    }
  }

  return 0;
}