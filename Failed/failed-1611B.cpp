#include <bits/stdc++.h>

using namespace std;

#define ll long long int

inline ll rec(ll a, const ll b) {
  if( (a <= 0) || (b <= 0) || (a+b<4) ) {
    return 0;
  }
  ll x, y, z, maximus;

  x = min(a, b) / 2;
  int a1 = a - (x * 2);
  int b1 = b - (x * 2);

  x = x + rec(a1, b1);

  if(a >= 3*b) {
    y = b;
  } else {
    y = a / 3;
  }
  int a2 = a - 3*y;
  int b2 = b - y;

  y = y + rec(a2, b2);

  if( b >= 3*a ) {
    z = a;
  } else {
    z = b / 3;
  }

  int a3 = a - z;
  int b3 = b - 3*z;

  z = z + rec(a3, b3);

  maximus = max(x, max(y, z));

  return maximus;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int T;
  ll a, b, maximus;
  string s;

  cin>>T;
  while(T--) {
    cin>>a>>b;
    maximus = rec(a, b);
    cout<<maximus<<"\n";
  }
  return 0;
}