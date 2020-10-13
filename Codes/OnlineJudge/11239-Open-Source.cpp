/*************************************************************************
  SPDX-License-Identifier: MIT
  Copyright (c) 2020 Qazi Fahim Farhan (@fahimfarhan)
  May the CodeForces be with you!
 ************************************************************************/

#include <cstdlib>
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
#include <unordered_map>
// #include <queue>
// #include <stack>
#include <algorithm>
// #include <functional>
#include <iomanip>      // std::setprecision


using namespace std;

#define PI 2*acos(0)
#define BLACK_LISTED "_"

//typedef long long int ll;
 #define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MOD = 1e9+7;

// int n,m;
vector<int> *g;
bool *isvisited;

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

bool isUpperCase(const char& ch) {
  return (('A' <= ch) && (ch <='Z'));
}

bool comparator(pair<int, string> p1, pair<int, string> p2) {
  if(p1.first > p2.first) { return true;  }
  else if(p1.first == p2.first) {
    return (p1.second < p2.second);
  }
  return false;
}

void start() {
  unordered_map<string, int> summary;
  unordered_map<string, string> isEnrolled;

  string s;
  string lastProjectName = "";
  while(getline(cin, s)){
    if(s == "0") {  exit(0);  }
    else if(s == "1") {  
      /* todo: print ans */ 
      vector<pair<int, string>> v;
      for(auto x : summary) {
        if(x.first != BLACK_LISTED) {
          v.push_back({x.second, x.first});
        }
      }
      summary.clear();
      isEnrolled.clear();

      sort(v.begin(), v.end(), comparator);
      for(auto x: v) {
        cout<<x.second<<" "<<x.first<<"\n";
      }
      break;  
    }
    else if(isUpperCase(s[0])){
      lastProjectName = s;
      summary[lastProjectName] = 0;
    }else{
      // this s is a student
      if(isEnrolled.count(s) == 0 ) {
        // case 1 this si the 1st time this dude is seeing any projects and commiting to it
        isEnrolled[s] = lastProjectName;
        summary[lastProjectName]++;
      }else if(isEnrolled.count(s) > 0 && isEnrolled[s] != lastProjectName) {
        // NOT OK backlist this dude
        summary[isEnrolled[s]]--;
        isEnrolled[s] = BLACK_LISTED;
      }
      // else if(isEnrolled.count(s) > 0 && isEnrolled[s] == lastProjectName) {
      //   // it's ok. btw this block is probably not needed
      // }
    } 
  }

}

int main(int argc, char const *argv[]){
  /* code */
  FastIO();

  while(true) {
    start();
  }
  return 0;
}