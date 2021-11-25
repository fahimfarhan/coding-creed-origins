#include <bits/stdc++.h>

using namespace std;

#define ll long long int

inline bool isPossible(const string& input) {
  int N = input.size();
  bool b = false;
  int n = 0;
  for(int i=0; i<N; i++) {
    n = input[i] - '0';
    if( (n&1) == 0 ) {
      b = true; break;
    }
  }
  return b;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int T;
  ll n;
  string s;

  cin>>T;
  while(T--) {
    cin>>s;
    int N = s.size();
    int first = s[N-1] - '0';
    int last = s[0] - '0';

    if( (first & 1) == 0) {
      cout<<0<<"\n";
    } else if( (last & 1) == 0) {
      cout<<1<<"\n";
    } else {
      if(isPossible(s)) {
        cout<<2<<"\n";
      } else {
        cout<<-1<<"\n";
      }
    }
  }
  return 0;
}