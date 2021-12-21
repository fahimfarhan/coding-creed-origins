#include<bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int t, n, *a, kount = 0;

  cin>>t;
  while(t--) {
    cin>>n;
    a = new int[n+1];
    for(int i=1; i<=n; i++) {
      cin>>a[i];
    }

    kount = 0;
    for(int i=1; i<=n; i++) {
      for(int j=i+1; j<=n; j++) {
        if((a[j] - a[i]) == (j - i)) {
          kount++;
        }
      }
    }

    cout<<kount<<"\n";
    delete[] a;
  }

  return 0;
}