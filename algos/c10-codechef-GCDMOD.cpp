#include<bits/stdc++.h>
#include <iostream>
#define ll long long int
#define MOD 1000000007
using namespace std;

ll calcPower(ll a, ll power, ll mod) {
  ll base = a;
  ll result = 1;
  ll one = 1;
  while (power) {
    if( (power&one) == one) {
      result = ((result % mod) * (base % mod)) % mod ;
      power--;
    }else{
      base = ((base%mod) * (base%mod))%mod;
      power = power >> 1;
    }
  }
  return result;
}

int main() {
  ll A,B,N,T, maximus;
  cin>>T;
  while(T--) {
    cin>>A>>B>>N;
    if(A == B) {
      maximus = calcPower(A, N, MOD) + calcPower(B, N, MOD) % MOD;
    }else{
      ll diff = abs(A-B);
      maximus = 0;
      for(ll i=1; i*i <= diff; i++) {
        if( (diff % i) == 0) {
          // i, and diff/i are divisors of diff=A-B
          ll temp1 = (calcPower(A, N, i) + calcPower(B, N, i))%i;
          if(temp1==0) {
           maximus = max(maximus, i);
          }

          ll j = diff / i;
          temp1 = (calcPower(A, N, j) + calcPower(B, N, j))%j;
          if(temp1 == 0) {
            maximus = max(maximus, j);
          }
        }
      }
    }

    maximus = maximus % MOD;
    cout<<maximus<<"\n";
  }
  return 0;
}