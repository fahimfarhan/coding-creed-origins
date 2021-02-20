#include <bits/stdc++.h>
using namespace std;

#define ll  int
#define N 100000

#define PRIME false
#define COMPOSITE true

vector<ll> primes; 

inline void seive() {
  vector<bool> isPrime(N,PRIME);
  
  isPrime[0] = COMPOSITE;
  isPrime[1] = COMPOSITE;

  for(int i=4; i<N; i+=2) {
    isPrime[i] = COMPOSITE;
  }

  for(int i=3; i<N; i+=2) {
    if(isPrime[i] == PRIME) {
      for(int j=2*i; j<N; j+=i) {
        isPrime[j] = COMPOSITE;
      }
    }
  }

  for(int i=2; i<N; i++) {
    if(isPrime[i]) {  primes.push_back(i);  }
  } 
}

inline void segmentedSeive(ll L, ll R) {
  L = max( (ll)2, L);
  ll size = R-L+1;
  vector<ll> v(size, PRIME);
  for(ll p: primes) {
    // if(p*p <= R) {
      ll start = (L/p)*p;
      if(start < L) { start+=p; }

      for(int i=start; i<=R; i+=p) {
        v[(i - L)] = COMPOSITE;
      }
    // }
  }

  for(int i=0; i<size; i++) {
    if(v[i] == PRIME) {
      cout<< (i + L) <<"\n";
    }
  }
}

int main() {
  seive();

  int T;
  ll L, R;
  cin>>T;
  while(T--) {
    cin>>L>>R;
    segmentedSeive(L, R);
    cout<<"\n";
  }
  return 0;
}