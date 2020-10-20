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

int main(int argc, char const *argv[]){
  /* code */
  FastIO();

  int T, N;
  string s;
  stack<char> st;

  cin>>T;
  while(T--) {
    cin>>s;
    N = s.size();
    for(int i=N-1; i>=0; i--) {
      if(st.empty()) {  st.push(s[i]);  }
      else if(s[i] == 'A'){
        if(st.top() == 'B') {
          st.pop();
        }else{
          st.push(s[i]);
        }
      }else if(s[i] == 'B') {
        if(st.top() == 'B') {
          st.pop();
        }else{
          st.push(s[i]);
        }
      }
    }

    string t = "";
    while(!st.empty()) {
      t += st.top();
      st.pop();
    }

    cout<<t<<" "<<t.size()<<"\n";
  }

  return 0;
}