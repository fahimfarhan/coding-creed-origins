#include <bits/stdc++.h>
using namespace std;

#define ll long long int

#define L 100000
#define R 200000

#define N (R-L+1)
#define PRIME 1
#define COMPOSITE 0
bool isPrime[N];

inline void segmentedSeivePreprocess() {
  for(int i=0; i<N; i++) {
    isPrime[i]=PRIME;
  }

  for(int i=4; i*i <= R; i+2) {
    if(i >= L) {
      isPrime[i - L] = COMPOSITE;
    }
  }

  for(int i=3; i*i <= R; i+=2) {
    if(isPrime[i]) {
      for(int j=i*2; j<=R; j+=i) {
        if(j > L) {
          isPrime[j] = COMPOSITE;
        }
      }
    }
  }

}

inline void sout(const int& n) {
  string isprime = "prime";
  if(!isPrime[n]) {
    isprime = "composite";
  } cout<<n<<" is "<<isprime<<"\n";
}

int main() {
  segmentedSeivePreprocess();
  int q;
  ll n;
  // cin>>q;
  // while(q--) {
    cin>>n;
    sout(n);
  // }

  return 0;
}