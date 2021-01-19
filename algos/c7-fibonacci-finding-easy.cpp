/*************************************************************************
  SPDX-License-Identifier: MIT
  Copyright (c) 2020 Qazi Fahim Farhan (@fahimfarhan)
  May the CodeForces be with you!
 ************************************************************************/
/**
// ⢀⣠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⣠⣤⣶⣶  ⠄⠄⠄⠄⠄⠄⢴⡶⣶⣶⣶⡒⣶⣶⣖⠢⡄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄  
// ⢀⣠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⣠⣤⣶⣶  ⠄⠄⠄⠄⠄⠄⢠⣿⣋⣿⣿⣉⣿⣿⣯⣧⡰⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
// ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⢰⣿⣿⣿⣿  ⠄⠄⠄⠄⠄⠄⣿⣿⣹⣿⣿⣏⣿⣿⡗⣿⣿⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
// ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⣀⣀⣾⣿⣿⣿⣿  ⠄⠄⠄⠄⠄⠄⠟⡛⣉⣭⣭⣭⠌⠛⡻⢿⣿⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
// ⣿⣿⣿⣿⣿⡏⠉⠛⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⣿  ⠄⠄⠄⠄⠄⠄⠄⠄⣤⡌⣿⣷⣯⣭⣿⡆⣈⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
// ⣿⣿⣿⣿⣿⣿⠀⠀⠀⠈⠛⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠛⠉⠁⠀⣿  ⠄⠄⠄⠄⠄⠄⠄⢻⣿⣿⣿⣿⣿⣿⣿⣷⢛⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
// ⣿⣿⣿⣿⣿⣿⣧⡀⠀⠀⠀⠀⠙⠿⠿⠿⠻⠿⠿⠟⠿⠛⠉⠀⠀⠀⠀⠀⣸⣿  ⠄⠄⠄⠄⠄⠄⠄⠄⢻⣷⣽⣿⣿⣿⢿⠃⣼⣧⣀⠄⠄⠄⠄⠄⠄⠄⠄⠄
// ⣿⣿⣿⣿⣿⣿⣿⣷⣄⠀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿  ⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣛⣻⣿⠟⣀⡜⣻⢿⣿⣿⣶⣤⡀⠄⠄⠄⠄⠄
// ⣿⣿⣿⣿⣿⣿⣿⣿⣿⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⣴⣿⣿⣿⣿  ⠄⠄⠄⠄⠄⠄⠄⠄⢠⣤⣀⣨⣥⣾⢟⣧⣿⠸⣿⣿⣿⣿⣿⣤⡀⠄⠄⠄
// ⣿⣿⣿⣿⣿⣿⣿⣿⡟⠀⠀⢰⣹⡆⠀⠀⠀⠀⠀⠀⣭⣷⠀⠀⠀⠸⣿⣿⣿⣿  ⠄⠄⠄⠄⠄⠄⠄⠄⢟⣫⣯⡻⣋⣵⣟⡼⣛⠴⣫⣭⣽⣿⣷⣭⡻⣦⡀⠄
// ⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠈⠉⠀⠀⠤⠄⠀⠀⠀⠉⠁⠀⠀⠀⠀⢿⣿⣿⣿  ⠄⠄⠄⠄⠄⠄⠄⢰⣿⣿⣿⢏⣽⣿⢋⣾⡟⢺⣿⣿⣿⣿⣿⣿⣷⢹⣷⠄
// ⣿⣿⣿⣿⣿⣿⣿⣿⢾⣿⣷⠀⠀⠀⠀⡠⠤⢄⠀⠀⠀⠠⣿⣿⣷⠀⢸⣿⣿⣿  ⠄⠄⠄⠄⠄⠄⠄⣿⣿⣿⢣⣿⣿⣿⢸⣿⡇⣾⣿⠏⠉⣿⣿⣿⡇⣿⣿⡆
// ⣿⣿⣿⣿⣿⣿⣿⣿⡀⠉⠀⠀⠀⠀⠀⢄⠀⢀⠀⠀⠀⠀⠉⠉⠁⠀⠀⣿⣿⣿  ⠄⠄⠄⠄⠄⠄⠄⣿⣿⣿⢸⣿⣿⣿⠸⣿⡇⣿⣿⡆⣼⣿⣿⣿⡇⣿⣿⡇
// ⣿⣿⣿⣿⣿⣿⣿⣿⣧⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣿⣿  ⠇⢀⠄⠄⠄⠄⠄⠘⣿⣿⡘⣿⣿⣷⢀⣿⣷⣿⣿⡿⠿⢿⣿⣿⡇⣩⣿⡇
// ⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿  ⣿⣿⠃⠄⠄⠄⠄⠄⠄⢻⣷⠙⠛⠋⣿⣿⣿⣿⣿⣷⣶⣿⣿⣿⡇⣿⣿⡇
*/

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
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  /*
  std::cout << std::fixed;
  std::cout << std::setprecision(10);
  cout << num1 << endl;
  */
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  /*
---------- Interactive problems ---------

  on each interactive questions' end, add `cout.flush()`
  say, cout<<"some weirdo question";
  cout<<"\n"; // end of question
  cout.flush(); // <-- just like this

  if still confusing, check out 1363D.cpp
    
*/
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


/*
fk+2   1 1   fk+1
fk+1 = 1 0   fk


F2 = M * F1
FN = M * FN-1 = M^2 FN-2 = M3 * FN-3 = ... = M^(N-1)*FN-(N-1) = M^(N-1)*F1
*/

// warning! F1[0] = 1, F1[1] = 0 this should be the order
inline vector<ll> fibMatrixMultiply(vector<ll> F1, vector<vector<ll>> M, int n) {  // failed
  vector<ll> FN(2, 0);
  int N = n - 1;
  M = M^N;

  FN[0] = M[0][0]*F1[0] + M[0][1] * F1[1];
  FN[1] = M[1][0]*F1[0] + M[1][1] * F1[1];

  return FN;
}

inline ll fibMatrixMultiply2(vector<ll> F1, int n) {
  int N = n ;
  vector<vector<ll>> M(2, vector<ll>(2,0));
  M[0][0] = 0;
  M[0][1] = 1;
  M[1][0] = 1;
  M[1][1] = 1;

  vector<vector<ll>> A = M^N;

  // vector<ll> FN(2, 0);
  // cout<<"debug "<<F1[0]<<" "<<F1[1]<<"\n"; cout.flush();
  ll FN = (F1[0]*A[0][0] + F1[1] * A[1][0]) % MOD;
  // FN[1] = F1[0]*A[0][1] + F1[1] * A[1][1];
  
  return FN;
}

inline ll start(vector<ll> F, int N) {
  
  if(N < 2) {
    return F[N]; // cout<<F[N]<<"\n";
  }else{
    return fibMatrixMultiply2(F, N);
  }
}

// inline void test() {
//   int realFib[100000] = {0};
//     vector<ll> v1 = {2,3};
//   realFib[0] = v1[0];
//   realFib[1] = v1[1];

//   for(int i=2; i<100000; i++) { realFib[i] = (realFib[i-1] + realFib[i-2]) % MOD; }

//   int N = 0;
//   while(true) {
//     cin>>N;
//     if(N == -1) { break;  }

//     int output1 = start(v1,N);

//     // cout<<"output1 = "<<output1 <<" "<<realFib[N-1]<<" "<<realFib[N]<<" "<<realFib[N+1]<<"\n";
//     cout<<"output1 = "<<output1<<" "<<realFib[N]<<"\n";
    
//     cout.flush();
//   }

// }

// inline void test2() {
// vector<vector<ll>> M(2, vector<ll>(2,0));
//   M[0][0] = 0;
//   M[0][1] = 1;
//   M[1][0] = 1;
//   M[1][1] = 1;

//   int N;
//   while(true) {
//     cin>>N;
//     if(N == -1) { break;  }
//     vector<vector<ll>> A = M^N;  
//     for(int i=0; i<2; i++) {
//       for(int j=0; j<2; j++) {
//         cout<<A[i][j]<<" ";
//       }cout<<"\n";
//       cout.flush();
//     }
//   }


// }

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

  // test();
  // test2();
  return 0;
}

