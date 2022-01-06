#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  bool mp[100001] = {false};

  int a, m, r;
  bool possible = true;
  cin>>a>>m;

  while(true) {
    r = a % m;
    if(mp[r]) {
      possible = false;
      break;
    }

    if( (a == 0) || (r == 0) ) {
      possible = true;
      break;
    }

    mp[r] = true;
    a = a + r;
  }

  if(possible) {
    cout<<"Yes\n";
  } else {
    cout<<"No\n";
  }

  return 0;
}