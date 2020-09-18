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

int getPrecedence(const char& op) {
  if(op == '^') { return 3; } // not needed in this problem. but for standard postfix, it is needed
  else if( (op == '*') || (op == '/') ) { return 2; }
  else if( (op == '+') || (op == '-') ) { return 1; }
  return 0;
}

bool isNumber(const char& ch){
  return ( (ch >='0') && (ch <='9') );
}

void start() {
  string s = "", token = "", result = "";
  stack<char> st;

  while(true) {
    getline(cin, token);
    if(token.length() == 0 || !cin) { break; }
    s = s + token;
  }

  for(int i=0; i<s.size(); i++) {
    char ch = s[i];
    if(isNumber(ch)) {
      result = result + ch;  
    }else if(ch == '(') {
      st.push(ch);
    }else if(ch == ')') {
      while(st.top()!='(') {
        result = result + st.top();
        st.pop();
      }st.pop(); // pops ( 
    }else{
      while( !st.empty() && getPrecedence(st.top()) >= getPrecedence(ch) ) {
        result = result + st.top();
        st.pop();
      }
      st.push(ch);
    }
  }
  while (!st.empty()) {
    result = result + st.top();
    st.pop();
  }

  cout<<result<<"\n";
} 

int main(int argc, char const *argv[]){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N;
  char ch;

  cin>>N;
  cin.ignore();
  cin.ignore();

  while(N--) {
    start();
    if(N) { cout<<"\n"; }
  }
  

  return 0;
}
