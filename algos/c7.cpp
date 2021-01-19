/*************************************************************************
  SPDX-License-Identifier: MIT
  Copyright (c) 2020 Qazi Fahim Farhan (@fahimfarhan)
  May the CodeForces be with you!
 ************************************************************************/

#include <iostream>
#include <climits>  // this includes INT_MIN, INT_MAX, ... ...
// #include <sstream>
// #include <cstdio>
// #include <cmath>
// #include <cstring>
// #include <cctype>
// #include <string>
#include <vector>
// #include <list>
// #include <set>
// #include <unordered_set>
// #include <map>
// #include <unordered_map>
// #include <queue>
// #include <stack>
#include <algorithm>
// #include <functional>
#include <iomanip>      // std::setprecision


using namespace std;

#define PI 2*acos(0)

//typedef long long int ll;
 #define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MOD = 1e9+7;

// int n,m;
vector<int> *g;
bool *isvisited;



inline void FastIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

}

inline vector<vector<ll>> operator*(vector<vector<ll>> lhs, vector<vector<ll>> rhs) {
  int N = lhs.size();
  vector<vector<ll>> res(N, vector<ll>(N, 0L));
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      for(int k=0; k<N; k++) {
        res[i][j] = (res[i][j] + (lhs[i][k]*rhs[k][j])% MOD ) % MOD;
      }
    }
  }
  return res;
}

inline vector<vector<ll>> operator^(vector<vector<ll>> base, int exp) {
  int N = base.size();
  vector<vector<ll>> res(N, vector<ll>(N, 0));

  for(int i=0; i<N; i++) {  res[i][i] = 1;  }
  while(exp > 0) {
    if( (exp & 1) == 1) {
      res = res * base;
    }
    base = base * base;
    exp = exp >> 1;
  }
  return res;
}

inline ll fibMatrixMultiply2(vector<ll> F1, int n) {
  int N = n ;
  vector<vector<ll>> M(2, vector<ll>(2,0));
  M[0][0] = 0;
  M[0][1] = 1;
  M[1][0] = 1;
  M[1][1] = 1;

  vector<vector<ll>> A = M^N;

  ll FN = (F1[0]*A[0][0] + F1[1] * A[1][0]) % MOD;
  
  return FN;
}

inline ll start(vector<ll> F, int N) {
  
  if(N < 2) {
    return F[N]; // cout<<F[N]<<"\n";
  }else{
    return fibMatrixMultiply2(F, N);
  }
}

int main(int argc, char const *argv[]){
  /* code */
  FastIO();
  int T;
  vector<ll> F(2,0); 
  int N;
  
  cin>>T;
  while(T--) {
    cin>>F[0]>>F[1]>>N;
    cout<<start(F, N)<<"\n";
  }

  return 0;
}

