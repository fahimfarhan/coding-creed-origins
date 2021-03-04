#include <bits/stdc++.h>
using namespace std;


#define ll long long int

ll T, N, Q, L, R, g;
ll *a, *prefixGcd, *suffixGcd;

inline void preprocessing() {
  a = new ll[N+2];
  prefixGcd = new ll[N+2];
  suffixGcd = new ll[N+2];
  prefixGcd[0] = 0;
  suffixGcd[N+1] = 0;

  for(int i=1; i<=N; i++) {  cin>>a[i]; }

  for(int i=1; i<=N; i++) {  prefixGcd[i] = __gcd(prefixGcd[i-1], a[i]); }
  for(int i=N; i> 0; i--) {  suffixGcd[i] = __gcd(suffixGcd[i+1], a[i]); }

}

inline void destructor() {
  delete[] a;
  delete[] prefixGcd;
  delete[] suffixGcd;
}

int main() {
  cin>>T;
  while(T--) {
    cin>>N>>Q;
    preprocessing();
    while (Q--) {
      cin>>L>>R;
      g = __gcd(prefixGcd[L-1], suffixGcd[R+1]);

      cout<<g<<"\n";
    }
    destructor();
  }

  return 0;
}