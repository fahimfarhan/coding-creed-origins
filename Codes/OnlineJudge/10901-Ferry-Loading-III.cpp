/*************************************************************************
  SPDX-License-Identifier: MIT
  Copyright (c) 2020 Qazi Fahim Farhan (@fahimfarhan)
  May the CodeForces be with you!
 ************************************************************************/

#include <iostream>
#include <climits>  // this includes INT_MIN, INT_MAX, ... ...
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iomanip>      // std::setprecision

using namespace std;

#define PI 2*acos(0)

#define LEFT 1
#define RIGHT 0
//typedef long long int ll;
 #define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MOD = 1e9+7;
// int n,m;
vector<int> *g;
bool *isvisited;

void FastIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int main(int argc, char const *argv[]){
  /* code */
  FastIO();
  ll T, n, t, m;
  ll time;
  ll arrivalTime;
  string side;
  queue<pair<ll,ll>> left, right;
  queue<ll> boat;
  ll *result;
  bool toogle = LEFT;
  ll maximus = 0;
  
  cin>>T;
  for(int c = 0; c < T; c++) {
    cin>>n>>t>>m;
    result = new ll[m+1];
    for(int i=0; i<m; i++) {
      cin>>arrivalTime>>side;
      if(side == "left") {
        left.push({i,arrivalTime});
      }else{
        right.push({i,arrivalTime});
      }
    }

    time = 0; // initial time
    toogle = LEFT;
    maximus = 0;
    while(!( left.empty() && right.empty() && boat.empty() )) {
      int next = 0;
      if(!left.empty() && !right.empty()) {
        next = min(left.front().second, right.front().second);
      }else if(left.empty() && !right.empty()) {
        next = right.front().second;
      }else if(!left.empty() && right.empty()) {
        next = left.front().second;
      }else{
        break;
      }

      if(next > maximus) {
        maximus = next;
      }

      if(toogle == LEFT) {
        while(!left.empty() && left.front().second <= maximus && boat.size() <n) {
          boat.push(left.front().first);
          left.pop();
        }
      }else{
        while(!right.empty() && right.front().second <= maximus && boat.size() <n) {
          boat.push(right.front().first);
          right.pop();
        }
      }

      toogle=!toogle;
      maximus+=t;

      while(!boat.empty()) {
        result[boat.front()] = maximus;
        boat.pop();
      }
    }
    for(int i=0; i<m; i++) {
      cout<<result[i]<<"\n";
    }
    if(c < T-1 ) {
      cout<<"\n";
    }
    delete[] result;
  }
  return 0;
}