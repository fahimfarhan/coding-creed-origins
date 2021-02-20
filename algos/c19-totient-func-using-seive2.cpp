#include <bits/stdc++.h>
using namespace std;

#define N 1000000

ll phi[N];

inline void totientFuncSeivePreprocess() {
  for(int i=0; i<N; i++) {
    phi[i] = i;
  }

  /*
  phi[1] = 1 cz gcd(1,1) = 1 O.O
  */

  for(int i=2; i<N; i++) {
    if(phi[i] == i) {  // this is a prime number
      int m = i - 1;
      for(int j=i; j<N; j+=i) {
        phi[j] = phi[j] / i * m;
      }
    }
  }
}

int main() {
  totientFuncSeivePreprocess();
  int Tm n;
  cin>>T;
  while(T--) {
    cin>>n;
    cout<<phi[n]<<"\n";
  }
  return 0;
}