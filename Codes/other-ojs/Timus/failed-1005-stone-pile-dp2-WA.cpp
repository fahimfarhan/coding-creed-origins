#include <bits/stdc++.h>
using namespace std;

inline int getMinimusDp(int *dp, const int *w, const int& size, 
    const int& index, const int& firstPile, const int& secondPile ) {
  
  if(dp[index]!=-1) {
    return dp[index];
  }

  if( (size == 0) || (index >= size) ) {
    dp[index] = abs(firstPile - secondPile);
    return dp[index];
  }

  // case 1: the current stone is in first pile
  int minimus1 = getMinimusDp(dp, w, size, (index+1), (firstPile + w[index]), secondPile );

  // case 2: the current stone is in second pile
  int minimus2 = getMinimusDp(dp, w, size, (index+1), firstPile, (secondPile+w[index]));

  int minimus = min(minimus1, minimus2);
  dp[index] = minimus;
  return dp[index];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int N, sum;
  int *w;
  int *dp;

  cin>>N;
  w = new int[N+1];
  for(int i=0; i<N; i++) {  cin>>w[i];  }
  sum = 0;
  for(int i=0; i<N; i++) {  sum+=w[i];  }
  dp = new int[sum+1];

  // memset(dp, -1, sizeof(dp));
  for(int i=0; i<=sum; i++) { dp[i] = -1; }

  int minimus = getMinimusDp(dp, w, N, 0, 0, 0);

  cout<<minimus<<"\n";

  delete[] dp;
  delete[] w;
  return 0;
}