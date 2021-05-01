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
// #include <regex>   // for regular expressions
#include <bitset> // for bitset

using namespace std;

#define PI 2*acos(0)

//typedef long long int ll;
 #define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MOD = 1e9+7;


#define GREATER 1
#define EQUAL 0
#define SMALLER -1

inline int bigIntComparator(string a, string b) {
  int sizeOfA = a.size();
  int sizeOfB = b.size();
  if(sizeOfA > sizeOfB) { return GREATER; }
  else if(sizeOfA < sizeOfB) { return SMALLER; }
  else{
    for(int i=0; i<sizeOfA; i++) {
      if(a[i]  < b[i]) {  return SMALLER; }
      else if(a[i] > b[i]) {  return GREATER; }
    }
  }
  return EQUAL;
}


inline string bigIntSum(string a, string b) {
  string summation = "";

  if(a.size() < b.size()) {
    swap(a, b);
  }

  int len1 = a.size(), len2 = b.size();

  int carry = 0;
  char ch;
  // int n = len2;
  int x = 0;
  for(int i=len1 - 1, j= len2-1; i>=0; i--, j--) {
    if(j >= 0) {
      x = (a[i] - '0') + (b[j] - '0') + carry;
    }else{
      x = (a[i] - '0') + carry;
    }
    if(x < 10) {  carry = 0;  }
    else{ carry = 1;  }

    x = x % 10;
    ch = x + '0';
    summation = ch + summation;
  }

  if(carry == 1) {
    summation = "1" + summation;
  }

  return summation;
}

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

int T, N;
int *u;
// ll *s;

bitset<100010> isPrime;
vector<int> *g;

inline void preprocess() {
  for(int i=0; i<=100010; i++) {
    isPrime[i] = 1;
  }
  isPrime[0] = 0;
  isPrime[1] = 0;
  isPrime[2] = 1; 

  for(int i=4; i<=100010; i++) {
    isPrime[i] = 0;
  }

  for(int i=3; i<=100010; i++) {
    if(isPrime[i] == 1) {
      for(int j = (i<<1); j<=100010; j+=i) {
        isPrime[j] = 0;
      }
    }
  }
}

inline void start() {
  cin>>N;
  u = new int[N+1];
  // s = new ll[N+1];

  int maximus = -1;

  for(int i=1; i<= N; i++) {  cin>>u[i]; maximus = max(maximus, u[i]);  }
  
  g = new vector<int>[maximus+1];
  
  int s;
  for(int i=1; i<= N; i++) {  cin>>s; g[u[i]].push_back(s);  }

  // cout<<"maximus = "<<maximus<<"\n";

  // delete[] s;
  delete[] u;

  // for(int i=1; i<=maximus; i++) {
  //   for(int j = 0; j< g[i].size(); j++) {
  //     cout<<g[i][j]<<" ";
  //   }cout<<"\n";
  // }
  // cout<<"----------------\n";

  for(int i = 1; i<=N; i++) {
    sort(g[i].begin(), g[i].end());
  }

  for(int i=1; i<=N; i++) {
    for(int j=1; j<g[i].size(); j++) {
      g[i][j] = g[i][j] + g[i][j-1];
    } 
  }

  for(int k = 1; k<=N; k++) {
    
  }
}

int main(int argc, char const *argv[]){
  /* code */
  FastIO();

  cin>>T;
  preprocess();
  while(T--) {
    start();
  }

  return 0;
}