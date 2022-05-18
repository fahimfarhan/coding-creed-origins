#include <bits/stdc++.h>
using namespace std;

int main() {
  int t, n, r, b, c, q;

  cin>>t;
  while(t--) {
    cin>>n>>r>>b;
    c = b + 1;
    q = r / c;

    string s = "";
    string t = "";

    for(int i=0; i<q; i++) {
      t += "R";
    }
    t += "B";

    for(int i=0; i<b; i++) {
      s += t;
    }

    int diff = n - s.size();

    for(int i=0; i<diff; i++) {
      s += "R";
    }

    cout<<s<<"\n";
  }

  return 0;
}