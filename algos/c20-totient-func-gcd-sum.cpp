#include <bits/stdc++.h>
using namespace std;

#define N 1000000
int phi[N];

inline void totientFuncSeivePreprocess() {
  for(int i=0; i<N; i++) {
    phi[i] = i;
  }

  for(int i=2; i<N; i++) {
    if(phi[i] == i) {  // i is a prime number
    int m = i - 1;
      for(int j=i; j<N; j+=i) {
        phi[j] = phi[j] / i * m; // (i-1);
      }
    }
  }
}

inline int getCount(int d, int n) {
  int m = n / d;
  return phi[m];
}

int main() {
  // Complexity = O(NlogN + Q sqrt(N))
  totientFuncSeivePreprocess();
  int q, n;
  cin>>q;
  while(q--) {
    cin>>n;
    int result = 0;
    for(int i=1; i*i<=n; i++) {
      if( (n % i) == 0) {
        int d1 = i;
        int d2 = n / i;

        result += d1 * getCount(d1, n);

        if(d1!=d2) {
          result += d2 * getCount(d2, n);
        }

      }
    }
    cout<<result<<"\n";
  }

  return 0;
}