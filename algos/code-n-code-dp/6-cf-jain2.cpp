#include <bits/stdc++.h>
using namespace std;

inline int shiftAmount(const char& ch) {
  if(ch == 'a') return 0;
  if(ch == 'e') return 1;
  if(ch == 'i') return 2;
  if(ch == 'o') return 3;
  if(ch == 'u') return 4;
  return 0;
}

const int M = (1<<5);  // 32
const int P = M-1;     // 31

int mp[M+1];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  // cerr<<"M = "<<M<<" P = "<<P<<"\n";

  int T, N, mask, result;
  string s;
  
  cin>>T;

  while(T--) {
    for(int i=0; i<M; i++) {
      mp[i] = 0;
    }

    cin>>N;
    for(int i=0; i<N; i++) {
      cin>>s;
      mask = 0;

      for(char ch: s) {
        mask = mask | (1 << shiftAmount(ch));
      }

      mp[mask]++;
    }

    
    result = 0;
    for(int i=0; i<M; i++) {
      for(int j = (i+1); j<M; j++) {
        if( ( i | j ) == P) {
          result = result + mp[i] * mp[j];
        }
      }
    }
    cout<<result<<"\n";
  }
  return 0;
}
