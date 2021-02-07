#include <bits/stdc++.h>
using namespace std;

#define N 1000001
bool isPrime[N] = {true};

inline void seivePreprocess() {
  for(int i=0; i<N; i++) {  isPrime[i] = true;  }
  isPrime[0] = false;
  isPrime[1] = false;

  for(int j=4; j<N; j+=2) {
    isPrime[j] = false;
  }

  for(int i=3; i<N; i+=2) {
    if(isPrime[i]) {
      for(int j=2*i; j<N; j+=i) {
        isPrime[j] = false;
      }
    }
  }
}

int phi(int n) {
  if(n < 2) {
    return 0;
  }

  if(isPrime[n]) {
    return (n-1);
  }

  set<int> primeDivisors;
  for(int i=1; i*i <= n; i++) {
    if( (n%i) == 0) {
      if(isPrime[i]) {
        primeDivisors.insert(i); // todo: upgrade this method
      }
      if(isPrime[(n/i)]) {
        primeDivisors.insert((n/i));
      }
    }
  }

  int etf = n;
  for(int p : primeDivisors) {
    //cerr<<p<<"debug";
    etf = (etf /p) * (p-1);
  }
  return etf;
}

int main() {
  seivePreprocess();
  int q, n;
  cin>>q;
  while(q--) {
    cin>>n;
    cout<<"Phi("<<n<<") = "<<phi(n)<<"\n";
  }
  return 0;
}