#include <bits/stdc++.h>
using namespace std;

#define MODULO 100000000

int getCount1(const int& n) {
  if( (n == 0) || (n == 1) ) {
    return 1;
  } 
  return 1 + getCount1( (n-1) );
}

int getCount2(const int& nw, const int& nh) {
  if(nw + nh == 0) {  return 1; }
  // infintry w
  
  int x = 0; 
  if(nw > 0) {
    x = 1 + getCount2((nw - 1), nh);
  }
  // knight h
  
  int y = 0; 
  if(nh > 0) {
    y = 1 + getCount2(nw, (nh - 1));
  }
  return (x + y) % MODULO;
}

int getCount3(const int& nw, const int& nh, const int& kw, const int& kh, const int& kwLimit, const int& khLimit) {
  if( (nw + nh) == 0) {  return 1; }
  // walk
  int w = 0;
  if(nw > 0 && kw > 0) {
    w = 1 + getCount3((nw-1), nh, (kw - 1), khLimit, kwLimit, khLimit );
  }
  // horse
  int h = 0;
  if(nh > 0 && kh > 0) {
    h = getCount3(nw, (nh-1), kwLimit, (kh-1), kwLimit, khLimit);
  }

  return (w + h);
}

int dp[101][101][11][11];

inline void initDp() {
  memset(dp, -1, sizeof(dp));
  for(int i=0; i<11; i++) {
    for(int j=0; j<11; j++) {
      dp[0][0][i][j] = 1;
    }
  }
}

inline int caesarsLegion(const int& nf, const int& nh, const int& kf, const int& kh, const int& kwLimit, const int& khLimit ) {
  if(dp[nf][nh][kf][kh] != -1) {
    return dp[nf][nh][kf][kh];
  }
  int f = 0;
  if( (nf > 0) && (kf > 0) ) {
    f = caesarsLegion((nf-1), nh, (kf-1), khLimit, kwLimit, khLimit);
  }

  int h = 0;
  if( (nh > 0) && (kh > 0) ) {
    h = caesarsLegion(nf, (nh-1), kwLimit, (kh-1), kwLimit, khLimit);
  }

  dp[nf][nh][kf][kh] = (f + h) % MODULO;
  return dp[nf][nh][kf][kh];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n1, n2, k1, k2;
  cin>>n1>>n2>>k1>>k2;

  initDp();

  cout<<caesarsLegion(n1, n2, k1, k2, k1, k2)<<"\n";
  return 0;
}