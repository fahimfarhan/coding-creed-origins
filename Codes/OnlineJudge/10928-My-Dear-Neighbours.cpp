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
#include <sstream>
#include <string>
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

  int T, P;
  cin>>T;
  // cerr<<"T "<<T<<"\n";
  while(T--) {
    cin>>P;
    cin.ignore();
    // cerr<<"P "<<P<<"\n";
  
    g = new vector<int>[P+1];
    int minimus = INT_MAX;

    string s;
    for(int u=1; u<=P; u++) {
      getline(cin, s);
      // cerr<<s<<"\n";
      stringstream ss(s);
      int v = 0;
      while(ss >> v) {
        g[u].push_back(v);
      }
      if(g[u].size() < minimus) {
        minimus = g[u].size();
      }
    }

    vector<int> result;
    for(int i=1; i<=P; i++) {
      if(g[i].size() == minimus) {
        result.push_back(i);
      }
    }

    for(int i=0; i<result.size() - 1; i++) {
      cout<<result[i]<<" ";
    }
    cout<<result[result.size() - 1]<<"\n";

    delete[] g;
  }

  return 0;
}