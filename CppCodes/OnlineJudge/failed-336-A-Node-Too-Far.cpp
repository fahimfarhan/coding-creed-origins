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
#include <vector>
// #include <list>
// #include <set>
// #include <unordered_set>
// #include <map>
#include <unordered_map>
#include <queue>
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

unordered_map<int, vector<int> > g;
unordered_map<int, bool> isvisited;
int testCase = 1;

void bfs(int src,int ttl) {
  queue<pair<int, int> > q;
  q.push({src, ttl});
  isvisited[src] = true;

  while(!q.empty()) {
    pair<int, int> top = q.front();
    q.pop();

    int ttl1 = top.second - 1;
    if(ttl1 == 0) {
      break;
    }
    int u, v;
    u = top.first;

    for(int i=0; i<g[u].size();i++) {
      v = g[u][i];
      if(!isvisited[v]) {
        isvisited[v] = true;
        q.push({v, ttl1});
      }
    }

    int kount = 0;
    for(auto node: isvisited) {
      if(!node.second) {
        kount++;
      }
    }

    cout<<"Case "<<testCase<<": "<<kount<<"  nodes not reachable from node "
    <<src<<" with TTL = "<<ttl<<".\n";

  }
}

bool start() {
  int N, u, v, maximus = INT_MIN;
  cin>>N;
  if(N == 0) {
    return false;
  }
  for(int i=0; i<N; i++) {
    cin>>u>>v;
    g[u].push_back(v);
    g[v].push_back(u);

    isvisited[u] = false;
    isvisited[v] = false;

  }

  int src, ttl;
  while(true) {
    cin>>src>>ttl;
    if( (src==0) && (ttl==0)) {
      break;
    }

    for(auto node : isvisited) {
      node.second = false;  // init isvisited
    }
    bfs(src, ttl);

  }
  return true;
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

  testCase = 1;

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
  bool b123 = true;
  while (b123) {
    b123 = start();
  }

  return 0;
}