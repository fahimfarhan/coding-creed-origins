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
#include <string>
#include <vector>
// #include <list>
// #include <set>
// #include <unordered_set>
// #include <map>
// #include <unordered_map>
// #include <queue>
#include <stack>
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

void start() {}

int main(int argc, char const *argv[]){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N;
  string s;
  int kount;
  bool isCorrect = true;

  int mp[100] = {0};
  mp[(int)'('] = 1;
  mp[(int)')'] = -1;
  mp[(int)'['] = 2;
  mp[(int)']'] = -2;
    
  cin>>N;
  while(N--) {
    // cin>>s;
    getline(cin, s);
      kount = 0;
      isCorrect = true;
      for(int i=0; i<s.size(); i++) {
        kount += mp[(int)s[i]];
          if(kount < 0) {
            isCorrect = false;
            break;
          }
        }

    if(isCorrect) {
        kount=0;
      for(int i=s.size(); i>=0; i--) {
        kount += mp[(int)s[i]];
        if(kount > 0) {
            isCorrect = false;
            break;
        }
      }
    }

    if(isCorrect) {
        cout<<"Yes\n";
    }else{
        cout<<"No\n";
    }
  
  
  }


  return 0;
}