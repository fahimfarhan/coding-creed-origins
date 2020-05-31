#include <bits/stdc++.h>
using namespace std;

#define DIAMETER first
#define DEPTH second

vector<int> *g;
int n,m;

int getLeftChild(int u) {
    if(g[u].size() >=1 ) {  return g[u][0]; }
    return -1;
}

int getRightChild(int u) {
    if(g[u].size() == 2) {  return g[u][1]; }
    return -1;
}


pair<int,int> calcDiameterAndMaxDepth(int u) {
    if(u == -1)          {  return {0, INT_MIN};  }
    if(g[u].size() == 0) {  return {0,0};   }
    int newDiameter, newDepth;
    
    pair<int, int> left = calcDiameterAndMaxDepth(getLeftChild(u));
    pair<int, int> right = calcDiameterAndMaxDepth(getRightChild(u));

    
    newDiameter = max( max( left.DIAMETER, right.DIAMETER ), (left.DEPTH + 1) + (right.DEPTH+1));
    newDepth = max(left.DEPTH, right.DEPTH) + 1;

    return {newDiameter, newDepth};
}

int main() {
    int u, v;
    int root;
    cin>>n>>m>>root;

    g = new vector<int>[n+1];

    for(int i=0; i<m; i++) {
        cin>>u>>v;
        g[u].push_back(v);
    }

    int diameterOfTree = calcDiameterAndMaxDepth(root).DIAMETER;

    cout<<diameterOfTree<<"\n";

    delete[] g;
    return 0;
}