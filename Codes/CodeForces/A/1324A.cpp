#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int t, n, *a;
  int oddCount = 0, evenCount = 0;

  cin>>t;
  while(t--) {
    evenCount = 0; oddCount = 0;
    cin>>n;
    a = new int[n+1];
    for(int i=0; i<n; i++) {  cin>>a[i];  }

    for(int i=0; i<n; i++) {
      if(a[i]&1 == 1) { oddCount++; }
      else {  evenCount++;  }
    }

    if((oddCount>0) && (evenCount>0)) { 
      cout<<"NO\n";
    } else {
      cout<<"YES\n";
    }

    delete[] a;
  }

  return 0;
}