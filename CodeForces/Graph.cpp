#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

#define WHITE 0
#define GRAY 1
#define BLACK 2

class Node{
public:
  int n, color;
  NODE(){n=0; color = 0; }
  ~NODE(){}
};

class Graph{
private:
  long long int numerator, denominator;
  int V, E;
  vector<int> *G;
  Node *v;
  int time;
    
public:
  Graph();
  ~Graph();
  void dfs();
  void dfsVisit(int u);
};

void Graph::dfsVisit(int u){
  time++;
  v[u].color = GRAY;

  vector<int>::iterator i;
  for(i=G[u].begin(); i!=G[u].end(); i++){
    int n = i->n;
    if(v[n].color == WHITE){  dfsVisit(n);}
  }
  v[u].color = BLACK;
  time++;
}

void Graph::dfs(){
  time = 0;

  for(int u=1; u<=V; u++){
    if(v[u].color == WHITE){
      dfsVisit(u);
    }
  }
}

Graph::Graph(){
  numerator = 0;
  denominator = 02;
  cin>>V;
  E = V-1;
  v = new Node[V+1];
  G = new vector<int>[V+1];
  int x, y;
  for(int i=0; i<E; i++ ){
    cin>>x>>y;
    G[x].push_back(y);
    G[y].push_back(x);
  }

  dfs();
}

Graph::~Graph(){
  if(v!=NULL){ delete[] v;}
  if(G!=NULL){ delete[] G;}
}

int main()
{
  Graph G;
  return 0;
}
