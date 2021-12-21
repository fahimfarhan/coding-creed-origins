/**
 *  https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/practice-problems/algorithm/sum-of-numbers-9/
 */


#include <bits/stdc++.h>
using namespace std;



int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int ar[15];
  int n, t, sum, p;

  cin>>t;
  while (t--){
    cin>>n;
    for(int i=0; i<n; i++) {  cin>>ar[i];  }

    cin>>p;
    bool flag = false;
    int tot = 1 << n;

    for(int mask = 0; mask < tot; mask++) {
      sum = 0;
      for(int i=0; i<n; i++) {
        int f = 1 << i;
        if( (mask&f) != 0) {
          sum += ar[i];
        }
      }

      if(sum == p) {
        flag = true; break;
      }
    }
    if(flag) {  cout<<"YES\n";  }
    else {  cout<<"NO\n"; }
  }
  

  return 0;
}