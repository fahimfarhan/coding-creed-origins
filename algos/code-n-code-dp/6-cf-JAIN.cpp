#include <bits/stdc++.h>
using namespace std;

long long int F[32];

inline int shiftAmount(const char& ch) {
  if(ch == 'a') { return 0; }
  if(ch == 'e') { return 1; }
  if(ch == 'i') { return 2; }
  if(ch == 'o') { return 3; }
  if(ch == 'u') { return 4; }
  return 0;
}


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int T, N;
  string s;

  cin>>T;
  while(T--) {
    cin>>N;
    for(int i=0; i<32; i++) {  F[i] = 0; }
    for(int i=0; i<N; i++) {
      cin>>s;
      int mask = 0;

      for(char ch: s) {
        mask = mask | (1 << shiftAmount(ch));
      }

      F[mask]++;
    }

    int res = 0;
    for(int i=1; i<32; i++) {
      for(int j=(i+1); j<32; j++) {
        if( (i|j) == 31 ) {
          res = res + F[i] * F[j];
        }
      }
    }
    cout<<res<<"\n";
  }

  return 0;
}