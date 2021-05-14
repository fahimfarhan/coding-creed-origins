#include <bits/stdc++.h>
using namespace std;

map< pair<int, int>, int> dp;

inline int getMinimusDp(const int *w, const int& size, const int& currPos, 
                        const int& firstPileWeight, const int& secondPileWeight) {
  if(dp[{firstPileWeight, secondPileWeight}]) {
    return dp[{firstPileWeight, secondPileWeight}];
  }

  if(size == 0 || currPos >= size) {
    int difference = abs(firstPileWeight - secondPileWeight);
    dp[{firstPileWeight, secondPileWeight}] = difference;
    dp[{secondPileWeight, firstPileWeight}] = difference;
    return difference;
  }
  
  // case 1: current stone is placed in pile 1
  int differenceForCase1 = getMinimusDp(w, size, (currPos+1), (firstPileWeight+w[currPos]), secondPileWeight);
  // case 2: current stone is placed in pile 2
  int differenceForCase2 = getMinimusDp(w, size, (currPos+1), firstPileWeight, (secondPileWeight+w[currPos]));

  int minimus = min(differenceForCase1, differenceForCase2);
  dp[{firstPileWeight, secondPileWeight}] = minimus;
  dp[{secondPileWeight, firstPileWeight}] = minimus;
  
  return minimus;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N, *w;
  cin>>N;
  w = new int[N+1];
  for(int i=0; i<N; i++) {
    cin>>w[i];
  }

  int minimus = getMinimusDp(w, N, 0, 0, 0);

  cout<<minimus<<"\n";

  delete[] w;
  return 0;
}