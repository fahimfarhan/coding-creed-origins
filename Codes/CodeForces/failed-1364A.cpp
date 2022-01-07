#include<bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int T, n, x, *a, *dp;
  int maximus = -1;
  int start, end;
  cin>>T;
  while(T--) {
    cin>>n>>x;
    a = new int[n+1];
    dp = new int[n+1];
    for(int i=0; i<n; i++) {  cin>>a[i];  }
    // for(int i=0; i<n; i++) {  a[i] %= x; }
    dp[0] = a[0];
    for(int i=1; i<n; i++) {
      dp[i] = (dp[i-1] + a[i]) % x;
    }

    /*for(int i=0; i<n; i++) {
      dp[i] %= x;
    }*/

    cout<<"debugx ";
    for(int i=0; i<n; i++) {  cout<<dp[i]<<" "; } cout<<"\n";
    maximus = 0;
    start = -1;
    end = -1;
    dp[n] = 0;
    for(int i=0; i<=n; i++) {
      if(dp[i] != 0) {
        if(start == -1) {
          start = i;
        }
        end = i;
      }
    }
    // maximus = max(maximus, count);  // cz the last partition is not calculated...
    // alternatively, set a[n] = 0, and run loop upto n. then no need for exceptional conditions

    // ans = lastNonZero - firstNonZero + 1
    maximus = end; // - start + 1;
    cout<<maximus<<"\n";    
    
    delete[] a;
    delete[] dp;
  }


  return 0;
}