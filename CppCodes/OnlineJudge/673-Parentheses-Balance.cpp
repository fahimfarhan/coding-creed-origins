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
  /* code */
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

  int N;
  string s;
  stack<char> st;
  bool isCorrect;

  cin>>N;
  getline(cin, s); // input remaining of the line containing N
  while(N--) {
    //  cin>>s; <---- fails to read empty line
    getline(cin,s);
    isCorrect = true;
    for(int i=0; i<s.size(); i++) {
      if( (s[i] == '(') || (s[i] == '[') ) {
        st.push(s[i]);  
      }else{
        if(st.size() == 0) {
          isCorrect = false;
          break;
        }else{
          if( (st.top() == '(') && (s[i] == ')') ) {
            st.pop();
          }else if( (st.top() == '[') && (s[i] == ']') ) {
            st.pop();
          }else if(s[i]!=' '){
            st.push(s[i]);
          }
        }
      }
    }

    if(st.size() != 0) {    isCorrect = false;  }
    
    if(isCorrect){
      cout<<"Yes\n";
    }else{
      cout<<"No\n";
    }
    
    while (!st.empty()) {
      st.pop();
    }

  }

  return 0;
}