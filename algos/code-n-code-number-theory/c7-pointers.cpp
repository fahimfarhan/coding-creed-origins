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
#define N 2

ll** multiplyMatrix(ll** lhs, ll** rhs) {

  ll** result;
  result = new ll*[N];
  for(int i=0; i<N; i++) {  result[i] = new ll[N];  }
  
  result[0][0] = 0; result[0][1] = 0; result[1][0] = 0; result[1][1] = 0;

  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      for(int k=0; k<N; k++) {
        result[i][j] = (result[i][j] + (lhs[i][k]*rhs[k][j])%MOD)%MOD;
      }
    }
  }
  return result;
}

ll** powerMatrix(ll** base, int n) {
  ll** result;
  result = new ll*[N];
  for(int i=0; i<N; i++) {  result[i] = new ll[N];  }
  
  result[0][0] = 1; result[0][1] = 0; result[1][0] = 0; result[1][1] = 1;  

  while (n>0) {
    if( (n&1) == 1) {
      result = multiplyMatrix(result, base);
    }
    base = multiplyMatrix(base, base);
    n = n >> 1;
  }
  return result;
}

inline ll fibMatrixMultiply(ll a, ll b, ll n) {
  ll **A = new ll*[N];
  for(int i=0; i<N; i++) {  A[i] = new ll[N]; }
  A[0][0] = 0; A[0][1] = 1; A[1][0] = 1; A[1][1] = 1;
  ll **M;
  M = powerMatrix( A,  n);
  ll FN = (a*M[0][0] + b * M[1][0]) % MOD;
  // FN[1] = F1[0]*A[0][1] + F1[1] * A[1][1];
  
  return FN;
}

inline void start() {
  ll a, b, n;
  cin>>a>>b>>n;

  if(n == 0) {
    cout<<a<<"\n";
  }else if(n == 1) {
    cout<<b<<"\n";
  }else{
    cout<<fibMatrixMultiply(a, b, n)<<"\n";
  }
}
int main() {
  int T;
  cin>>T;
  while(T--) {
    start();
  }
  return 0;
}


//  ![](https://komarev.com/ghpvc/?username=mahmud92542&color=red)