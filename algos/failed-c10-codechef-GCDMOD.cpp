#include <bits/stdc++.h>
#include <iostream>

#define ll long long int // int64t lagte pare
#define MOD 1000000000+7
using namespace std;


inline int calcModularPower(ll base, ll power, ll mod) {
  if(power == 0) return 1;
  if(power == 1) return base % mod;

  ll p = power >> 1;
  ll output = calcModularPower(base, p, mod);
  output = (output * output) % mod;
  if( (power & 1) == 1) {
    output = (output * (base% mod) ) % mod;
  }
  return output;
}

int main() {
  int T;
  ll N, A, B, ApN, BpN, Sum, Diff;
  ll mygcd;

  cin>>T;
  while(T--) {
    cin>>A>>B>>N;
    /**
    gcd (ApN + BpN , |A-B|) % MOD == ?
    */
    Diff = abs(A-B) % MOD;
    ApN = calcModularPower(A, N, Diff);
    BpN = calcModularPower(B, N, Diff);

    Sum = (ApN + BpN) % Diff;
    mygcd = __gcd(Sum, Diff);
 
    mygcd = mygcd % MOD;
    cout<<mygcd<<"\n";
  }
  return 0;
}