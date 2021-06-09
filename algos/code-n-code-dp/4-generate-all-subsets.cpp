#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  char ch[4] = {'A', 'B', 'C', 'D'};
  int n = 4;

  int total = 1 << n;
  
  for(int N=0; N<total; N++) {
    for(int i=0; i<n; i++) {
      int F = 1 << n;
      if( (N&F) != 0) {
        cout<<ch[i]<<"";
      }
    }cout<<"\n";
  }

  return 0;
}