#include <bits/stdc++.h>
#include <cmath>
#define ll long long int
#define MOD 1000000000 + 7
using namespace std;


/**
gcd(someHudeNumber, 90) = ?
potential candidates = {1,2,3,5, 15, 18, 36, 30,45,90} // etc koyekta chhara porse
Maximus from potential candidates that divides someHugeNumber is the result!
*/

inline int calcModularPower(ll base, ll power, ll mod) {
  if(power == 0) {  return 1; }
  if(power == 1) {  return base % mod; }
  ll p = power >> 1;
  ll output = calcModularPower(base, p, mod);
  output = (output * output) % mod;
  if( (power & 1) == 1) {
    output = (output * base)%mod;
  }
  return output;
}

int main() {
  ll T, A, B, N, diff, ApN, BpN;
  vector<ll> potentialCandidates;
  cin>>T;
  while(T--) {
    cin>>A>>B>>N;
    if(A == B) {
      ll output = calcModularPower(A, N, MOD) + calcModularPower(A, N, MOD);
      output = output % MOD;
      cout<<output<<"\n";

    }else{
    if(A > B) { diff = A - B; }
    else{ diff = B - A; }

    potentialCandidates.clear();
    ll M = sqrt(diff) + 1;
 
    for(ll i=1; i<=M; i++) {
      if( (diff % i) == 0) {
        potentialCandidates.push_back(i);
      }
    }
    potentialCandidates.push_back(diff);

    M = potentialCandidates.size() - 1;
    ll maximus = -1;
    for(int i=M; i>=0; i--) {
      ll d = potentialCandidates[i];
      ApN = calcModularPower(A, N, d);
      BpN = calcModularPower(B, N, d);

      ll temp = (ApN + BpN) % d; 

      if( temp == 0 ) {  maximus = d; break;  }
    }

    maximus = maximus % MOD;
    cout<<maximus<<"\n";
    }


  } 
  return 0;
}