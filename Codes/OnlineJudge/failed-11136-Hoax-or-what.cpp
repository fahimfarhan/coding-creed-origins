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
#include <iterator>
#include <sstream>
#include <string>
#include <vector>
// #include <list>
#include <set>
// #include <unordered_set>
// #include <map>
// #include <unordered_map>
// #include <queue>
// #include <stack>
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

void start() {
  int n = 0, m = 0, totalKost = 0;
  string line;

  multiset<int> multiSet;

  cin>>n;
  if(n == 0) {  exit(0);  }

  getline(cin, line); // the rest of the line after n
  
  for(int i=0; i<n; i++) {
    getline(cin, line);
    stringstream ss(line);

    m = 0;
    while(ss >> m) {
      if(m!=0) {  multiSet.insert(m); }      
    }

    for(auto x: multiSet) { cout<<x<<" "; }
    cerr<<"\n";
    auto ptrMinimus = min_element(multiSet.begin(), multiSet.end());
    auto ptrMaximus = max_element(multiSet.begin(), multiSet.end());
    
    auto itMinimus = multiSet.begin();
    int minimus = *itMinimus;

    auto itMaximus = multiSet.end();
    itMaximus--;

    int maximus = *itMaximus;

    int dKost = maximus - minimus;
    totalKost += dKost;

    multiSet.erase(itMinimus);
    multiSet.erase(itMaximus);

  }

  cout<<totalKost<<"\n";
  multiSet.clear();

}

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
  while(true) {
    start();
  }
  return 0;
}