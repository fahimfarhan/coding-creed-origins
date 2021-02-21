#include <bits/stdc++.h>
using namespace std;

int main() {

  int T, n, maximus, tempGcd;
  cin>>T;
  while(T--) {
    cin>>n;

    maximus = 0;
    for(int i=1; i<n; i++) {
      for(int j=i+1; j<=n; j++) {
        tempGcd = __gcd(i,j);
        maximus = max(maximus, tempGcd);
      }
    }

    cout<<n<<" "<<maximus<<"\n";
  }
  return 0;
}