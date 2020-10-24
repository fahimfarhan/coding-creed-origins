#include <bits/stdc++.h>
using namespace std;

vector<int> pset(1000);
vector<int> setSize(1000);
int setCount = 0;

void initPset(int size) { 
  pset.resize(size); 
  setSize.resize(size);
  setCount = size; 
  for(int i=0; i<size; i++){
    pset[i] = i;
    setSize[i] = 1;
  }  
}

int findSet(int i) {
  if(pset[i] == i) return i;
  else return pset[i] = findSet(pset[i]);
}

void unionSets(int i, int j) {
  int findSetI = findSet(i);
  int findSetJ = findSet(j);
  if(pset[findSetI] != findSetJ) {
    setCount--;
    pset[findSetI] = findSetJ;
    setSize[findSetJ] = setSize[findSetI] + setSize[findSetJ];
  }
}

bool isSameSet(int i, int j) {
  return (findSet(i) == findSet(j));
}

void unionSetsOriginal(int i, int j) {
  pset[findSet(i)] = findSet(j);
}

int sizeOfSet(int i) {
  return 0;
}

int main() {

  return 0;
}