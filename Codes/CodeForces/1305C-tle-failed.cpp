#include <bits/stdc++.h>
#define ll long long int

using namespace std;



int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, m;
  ll *a;
  cin>>n>>m;
  a = new ll[n+1];
  
  for(int i=0; i<n; i++) {  cin>>a[i];  }

  ll result = 1;
  ll delta = 0;

  for(int i=0; i<n; i++) {
    for(int j=i+1; j<n; j++) {
      delta = abs(a[i] - a[j]);

      result = (result * delta) % m;
    }
  } 

  cout<<result<<"\n";

  delete[] a;

  return 0;
}