#include <bits/stdc++.h>
#include <ios>
#include <iostream>
using namespace std;

inline void printPrimeFactorization(const int& N) {
  int kount = 0, M = N;
  for(int i=2; i*i<=N; i++) {
    if( (N%i) == 0) {
      kount = 0;
      M = N;
      while( (M%i) == 0) {
        kount++;
        M = M/i;
      }
      cout<<i<<"^"<<kount<<"\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  printPrimeFactorization(10);
  cout<<"--------------------------\n";
  printPrimeFactorization(20);
  cout<<"--------------------------\n";
  return 0;
}