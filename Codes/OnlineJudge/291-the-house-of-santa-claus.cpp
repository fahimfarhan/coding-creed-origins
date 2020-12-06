#include <algorithm>
#include <bits/stdc++.h>
#include <ios>
#include <iostream>
using namespace std;

#define N 6

vector<long> adjacent[N], result;
bool notVisited[N][N];

void addEdge(int u, int v) {
  adjacent[u].push_back(v);
  adjacent[v].push_back(u);

  notVisited[u][v] = false;
  notVisited[v][u] = false; 
}

bool drawing() {
  for(long i=1; i<N; i++) {
    for(long j=1; j<N; j++) {
      if(!notVisited[i][j]) {
        return false;
      }
    }
  }
  return true;
}

void backtrack(long pos, long soln) {
  if(soln > 1e8) {
    if(drawing()) result.push_back(soln);
    return;
  }

  for(long v : adjacent[pos]) {
    if(!notVisited[pos][v]) {
      long r = soln * 10 + v;
      notVisited[pos][v] = true;
      notVisited[v][pos] = true;
      backtrack(v, r);
      notVisited[pos][v] = false;
      notVisited[v][pos] = false;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      notVisited[i][j] = true;
    }
  }

  addEdge(1, 2);
  addEdge(2, 3);
  addEdge(3, 4);
  addEdge(4, 5);

  addEdge(1, 3);
  addEdge(2, 5);
  addEdge(3, 5);

  addEdge(1, 5);

  backtrack(1, 1);

  sort(result.begin(), result.end());

  for(auto i : result) {
    cout<<i<<"\n";
  }

  return 0;
}