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
#include <functional>
#include <iomanip>      // std::setprecision
// #include <regex>   // for regular expressions

using namespace std;

#define PI 2*acos(0)

//typedef long long int ll;
 #define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MOD = 1e9+7;

#define GREATER 1
#define EQUAL 0
#define SMALLER -1

int bigIntComparator(string a, string b) {
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
// int n,m;
vector<int> *g;
bool *isvisited;

void start() {}

void FastIO() {
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

string bigIntSum(string a, string b) {
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

/*
void test() {
  cout<<bigIntSum("1", "1")<<"\n";
  cout<<bigIntSum("10", "1")<<"\n";
  cout<<bigIntSum("1", "10")<<"\n";
  cout<<bigIntSum("9", "9")<<"\n";
  cout<<bigIntSum("123456789", "123456789")<<"\n";

  cout<<bigIntComparator("123", "123")<<"\n";
  cout<<bigIntComparator("123", "120")<<"\n";
  cout<<bigIntComparator("111", "123")<<"\n";
  cout<<bigIntComparator("10", "1")<<"\n";
  cout<<bigIntComparator("9", "10")<<"\n";
} 
*/

#define N 1000 // 00000

string f[N];

void preprocess() {
  f[0] = "1";
  f[1] = "2";

  for(int i=2; i<N; i++) {
    f[i] = bigIntSum(f[i-1] , f[i-2]);
  }
}

int lowerBound(string input) {
  int lo = 0;
  int hi = N-1;
  int mid = 0;
  int value = 0;
  while(hi - lo > 10) {
    mid = lo + (hi - lo)/ 2;
    value = bigIntComparator(f[mid], input);
    if(value == GREATER) {
      lo = mid;
    }else if(value == SMALLER) {  hi = mid; }
    else if(value == EQUAL) { return mid; }
  } 

  int i = 0;
  for(i=lo; i<=hi;  i++) {
    value = bigIntComparator(f[i], input);
    if( value == EQUAL || value == GREATER) {
      // return i;
      break;
    }
  }
  return i;
}

int upperBound(string input) {
  int lo = 0;
  int hi = N-1;
  int mid = 0;
  int value = 0;
  while(hi - lo > 10) {
    mid = lo + (hi - lo)/ 2;
    value = bigIntComparator(f[mid], input);
    if(value == GREATER) {
      lo = mid;
    }else if(value == SMALLER) {  hi = mid; }
    else if(value == EQUAL) { return mid; }
  } 

  int i = 0;
  for(i=lo; i<=hi;  i++) {
    value = bigIntComparator(f[i], input);
    if( value == EQUAL || value == SMALLER ) {
      // return i;
      break;
    }
  }
  return i;
}

int main(int argc, char const *argv[]){
  /* code */
  FastIO();
  preprocess();


    
  
  string a, b;
  while(true) {
    cin>>a>>b;
    if(a == "0" && b == "0") {  break;  }
  
    int kount = 0;
    int start = 0; int end = 0;
    bool isStartInclusive, isEndInclusive;
    for(int i=0; i<N; i++) {
      int value = bigIntComparator(f[i], a);
      if(value == EQUAL || value == GREATER) {
        start = i;
        isStartInclusive = (value == EQUAL);
        break;
      }
    }

    for(int i=start; i < N; i++) {
      int value = bigIntComparator(b, f[i]);
      if(value == EQUAL || value == SMALLER) {
        end = i;
        isEndInclusive = (value == EQUAL);
        break;
      }
    }

    kount = end - start + 1;
    // if(!isStartInclusive) { kount--;  }
    if(!isEndInclusive) { kount--;  }

    cout<<kount<<"\n";
  }
  
 
  return 0;
}