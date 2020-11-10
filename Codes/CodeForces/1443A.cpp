#include <bits/stdc++.h>
using namespace std;

int main() {
  int T, n;
  cin>>T;
  while(T--) {
    cin>>n;
    for(int i=4*n; i>= 2*n+2; i-=2) {
      cout<<i<<" ";
    }cout<<"\n";
  }
  return 0;
}
