#include <bits/stdc++.h>
using namespace std;

#define N 1000000

int phi[N];
bool isPrime[N];

inline void preprocessTotientFuncUsingSieve1() {
  for(int i=1; i<N; i++) {
    phi[i] = i; isPrime[i] = true;
  }

  // calc primes!
  isPrime[0] = false;
  isPrime[1] = false;
  for(int i=4; i<N; i+=2) {
    isPrime[i] = false;
  }

  for(int i=3; i<N; i+=2) {
    if(isPrime[i]) {
      for(int j=2*i; j<N; j+=i) {
        isPrime[j] = false;
      }
    }
  }

  // calc phi!
  for(int i=1; i<N; i++) {
    if(isPrime[i]) {
      for(int j=i; j<N; j+=i) {
        phi[j] = phi[j]/i*(i-1);
      }
    }
  }
}

inline void preprocessPhi() {
  /*
  phi[1] = 1 cz gcd(1,1) = 1 O.O
  */
  for(int i=1; i<N; i++) {
    phi[i] = i;
  }
  for(int i=2; i<N; i+=2) {
    phi[i] = phi[i] / 2 * 1;
  }

  for(int i=3; i<N; i+=2) {
    if(phi[i] == i) {  // this means this is a prime, so we can apply this!
      for(int j=i; j<N; j+=i) {
        phi[j] = phi[j] / i * (i-1);
      }
    }
  }
}

int main() {
  preprocessPhi();

  int T, n;
  cin>>T;
  while(T--) {
    cin>>n;
    cout<<"phi["<<n<<"] = "<<phi[n]<<"\n";
  }
  return 0;
}