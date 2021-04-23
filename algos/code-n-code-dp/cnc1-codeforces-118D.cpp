#include <bits/stdc++.h>
using namespace std;


/*

int caesarsLegions1(const int& n) {
  if(n == 0) {
    return 1;
  } if(n == 1) {  return 1; }

  return 1 + caesarsLegions1( (n-1) );
}

int caesarsLegion2(int n, int f, int h) {
  if(n == 0) {
    return 1;
  }
  if(n == 1) {
    return 1;
  }
  // case horse
  int x = 0;
  if(h > 0) x = caesarsLegion2((n-1), f, (h-1));

  // case infintry
  int y = 0;
  if(f > 0) y = caesarsLegion2((n-1), (f-1), h);
  return (x+y);
}

int caesarsLegion3(const int& nf, const int& nh, const int& f, const int& h, const int& limitF, const int& limitH) {
  // x = foot, y = horse
  int x = 0; 
  int y = 0;

  if( (nf+nh) == 0) {  return 1; } 
  
  // foot
  if( (nf > 0) && (f > 0) ) {
    x = caesarsLegion3( (nf-1), nh, (f-1), limitH, limitF, limitH);
  }

  // horse
  if( (nh > 0) && (h > 0) ) {
    y = caesarsLegion3( nf, (nh - 1), limitF, (h-1) , limitF, limitH);
  }

  return (x + y);
}

*/


#define MOD 100000000



int ****dp;

inline void initDp(const int& n1, const int& n2, const int& k1, const int& k2) {
  dp = new int***[n1+1];
  for(int i=0; i<=n1; i++) {
    dp[i] = new int**[n2+1];
    for(int j=0; j<= n2; j++) {
      dp[i][j] = new int*[k1+1];
      for(int k = 0; k <= k1; k++) {
        dp[i][j][k] = new int[k2+1];
      }
    }
  }

  for(int i=0; i<=n1; i++) {
    for(int j=0; j<= n2; j++) {
      for(int k = 0; k <= k1; k++) {
        for(int l=0; l <= k2; l++) {
          if( (i|j) == 0 ) {
            dp[i][j][k][l] = 1;
          }else{
            dp[i][j][k][l] = -1;
          }
        }
      }
    }
  }
}

inline void destructor(const int& n1, const int& n2, const int& k1, const int& k2) {
  for(int i=0; i<=n1; i++) {
    for(int j=0; j<= n2; j++) {
      for(int k = 0; k <= k1; k++) {
        delete[] dp[i][j][k]; //  = new int[k2+1];
      }
      delete[] dp[i][j]; // = new int*[k1+1];
    }
    delete[] dp[i]; // = new int**[n2+1];
  }
  delete[] dp;
}

inline int caesarsLegion(const int& nf, const int& nh, const int& f, const int& h, const int& limitF, const int& limitH) {
  if(dp[nf][nh][f][h] != -1) {
    return dp[nf][nh][f][h];
  }
  
  // X = foot
  int x = 0;
  if( (nf > 0) && (f > 0) ) {
    x = dp[(nf - 1)][nh][(f-1)][limitH];
    if(x == -1) {
      dp[(nf - 1)][nh][(f-1)][limitH] = caesarsLegion((nf-1), nh, (f-1), limitH, limitF, limitH);
      x = dp[(nf - 1)][nh][(f-1)][limitH];
    }
  }
  // Y = horse
  int y = 0; 
  if( (nh > 0) && (h>0) ) {
    y = dp[nf][(nh-1)][limitF][(h-1)];
    if(y == -1) {
      dp[nf][(nh-1)][limitF][(h-1)] = caesarsLegion(nf, (nh-1), limitF, (h-1), limitF, limitH);
      y = dp[nf][(nh-1)][limitF][(h-1)];
    }
  }

  dp[nf][nh][f][h] = (x + y) % MOD;
  return dp[nf][nh][f][h];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n1, n2, k1, k2;
  cin>>n1>>n2>>k1>>k2;

  // step 1
  //int step1 = caesarsLegions1((n1+n2));
  // step 2
  //int step2 = caesarsLegion2((n1+n2), k1, k2);
  // step 3
  //int step3 = caesarsLegion3( n1, n2, k1, k2, k1, k2);
  //cout<<step3<<"\n"; 

  initDp(n1, n2, k1, k2); 

  int step4 = caesarsLegion(n1, n2, k1, k2, k1, k2);
  cout<<step4<<"\n";

  destructor(n1, n2, k1, k2); 
  return 0;
}