#include <bits/stdc++.h>

using namespace std;

class Node{
public:
  int p, rank;
  Node() {  p = 0; rank = 0;  }
};

vector<Node> pset(1000);
vector<int> setSize(1000);
int setCount = 1000;

void initSize(int N) {
  pset.resize(N);
  setSize.resize(N);
  setCount = N;
  for(int i=0; i<N; i++) {
    pset[i].p = i;
    pset[i].rank = 0;
    setSize[i] = 1;
  }
}

int findSet(int i) {
  if(pset[i].p == i) return i;
  else {
    pset[i].p = findSet(pset[i].p);
    return pset[i].p;
  }
}

void unionSet(int i, int j) {
  int iroot = findSet(i);
  int jroot = findSet(j);

  if(iroot!=jroot) {
    if(pset[iroot].rank < pset[jroot].rank) {
      pset[iroot].p = jroot;
      setSize[iroot]+=setSize[jroot];

    }else if(pset[iroot].rank > pset[jroot].rank) {
      pset[jroot].p = iroot;
      setSize[jroot]+=setSize[iroot];
    }else{
      pset[jroot].p = iroot;
      pset[iroot].rank++;
    
      setSize[iroot]+=setSize[jroot];
    }
    setCount--;
  }
}

int getSetCount() {
  return setCount;
}

int getSetSize(int i) {
  return setSize[findSet(i)];
}

bool isSameSet(int i, int j) {
  return (findSet(i) == findSet(j));
}

int main() {


  return 0;
}