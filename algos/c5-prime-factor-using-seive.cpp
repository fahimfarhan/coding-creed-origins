#include <bits/stdc++.h>
#include <ios>
using namespace std;

#define N 1000001
int dp[N];

void seivepreprocess() {
  for(int i=0; i<N; i++) {  dp[i] = -1; }
  dp[0] = 0;
  dp[1] = 1;

  for(int i=2; i<N; i++) {
    if(dp[i] == -1) {
      for(int j=i; j<N; j+=i) {
        dp[j] = i;
      }
    }
  }
}

void recursivePrimeFactorization(int n) {
  if(n == 1) {  return; }
  // cout<<n<<" ";
  if(dp[n] != -1) {
      cout<<dp[n]<<" ";
    int m = n / dp[n];
    recursivePrimeFactorization(m);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  seivepreprocess();

  recursivePrimeFactorization(38);
  cout<<"\n====================\n";

    recursivePrimeFactorization(48);
  cout<<"\n====================\n";

    recursivePrimeFactorization(100);
  cout<<"\n====================\n";

  return 0;
}