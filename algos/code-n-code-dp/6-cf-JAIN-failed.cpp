#include <bits/stdc++.h>
using namespace std;

int T, N;
int M;
vector<string> s;

vector<int> v;

inline int shiftAmount(const char& ch) {
  if(ch == 'a') { return 1; }
  if(ch == 'e') { return 2; }
  if(ch == 'i') { return 3; }
  if(ch == 'o') { return 4; }
  if(ch == 'u') { return 0; }
  return 0;
}

inline int bitmask(string s) {
  int m = 0;
  int k = 0;
  for(int i=0; i<s.size(); i++) {
    k = 1 << shiftAmount(s[i]);
    m = m | k;
  }
  return m;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  M = 1 << 6;
  M = M - 1;

  cin>>T;
  while(T--) {
    cin>>N;
    // s = new string[N+1];
    s.resize(N+1);
    for(int i=0; i<N; i++) {
      cin>>s[i];
    }

    for(int i=0; i<N; i++) {
      int m = bitmask(s[i]);
      v.push_back(m);
    }

    int count = 0;
    for(int i=0; i<v.size()-1; i++) {
      for(int j=i+1; j<v.size(); j++) {
        int tempOr = v[i] | v[j];
        if(tempOr == M) {
          count++;
        }
      }
    }

    cout<<count<<"\n";
    v.clear();
    // delete[] s;
  }

  return 0;
}