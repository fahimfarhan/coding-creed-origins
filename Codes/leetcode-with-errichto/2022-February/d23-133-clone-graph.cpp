#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
private:
  unordered_map<int, bool> isVisited;
  unordered_map<int, Node*> mp;
  // run 2 dfs
  // 1st dfs to explore nodes, and create clonedNodeMap
  // clear isVisited
  // 2nd dfs to update the vector of the nodes 
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) {
          return nullptr;
        }
        dfsExploreNodes(node);
        dfsUpdateNeighbours(node);

        int nodeVal = node->val;
        return mp[nodeVal];
    }

    void dfsUpdateNeighbours(Node* u) {
      if(u == nullptr) {
        return;
      }
      int uVal, vVal;
      uVal = u->val;
      isVisited[uVal] = true;
      Node* uClone = mp[uVal];

      for(auto v: u->neighbors) {
        vVal = v->val;
        Node *vClone = mp[vVal];
        uClone->neighbors.push_back(vClone);
        vClone = nullptr;
      }

      for(auto v: u->neighbors) {
        vVal = v->val;
        if(!isVisited[vVal]) {
          dfsUpdateNeighbours(v);
        }
      }

      uClone = nullptr;
    }

    void dfsExploreNodes(Node* u) {
      if(u == nullptr) {
        return;
      }
      int uVal = u->val;
      int vVal = 0;
      bool cloneExists = false;
      Node* clone = new Node(uVal);
      mp[uVal] = clone;
      
      for(auto v: u->neighbors) {
        vVal = v->val;
        cloneExists = mp.find(vVal) != mp.end();
        if(!cloneExists) {
          dfsExploreNodes(v);
        }
      }

      clone = nullptr;
    }
};

int main() {
  return 0;
}