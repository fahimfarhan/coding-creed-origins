#include <bits/stdc++.h>
using namespace std;


inline int f(const int *w, const int& size, const int& firstPile, const int& secondPile, const int& currPos) {
  if( (size == 0) || (currPos >= size)) {
    return abs(firstPile - secondPile);
  }

  // case 1: curr stone is in firstPile
  int differenceForCase1 = f(w, size, (firstPile+w[currPos]), secondPile, (currPos+1));

  // case2: curr stone is in secondPile
  int differenceForCase2 = f(w, size, firstPile, (secondPile+w[currPos]), (currPos+1));

  int minimus = min(differenceForCase1, differenceForCase2);
  return minimus;
}



int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int N;
  int *w;

  cin>>N;
  w = new int[N+1];

  for(int i=0; i<N; i++) {
    cin>>w[i];
  }

  int minimus = f(w, N, 0, 0, 0);
  cout<<minimus<<"\n";

  delete[] w;
  return 0;
}