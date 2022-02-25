#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
      if(head == nullptr) { return nullptr; }
      Node* p = head;
      
      unordered_map<int, Node*> mp;
      int pVal;
      Node *pNext, *pRandom;
      Node *clone = nullptr, *prevClone = nullptr;

      Node* newHead = nullptr;

      while(p != nullptr) {
        pVal = p->val;
        clone = new Node(pVal);
        if(newHead == nullptr) {    newHead = clone;    } 
        mp[pVal] = clone;

        if(prevClone!=nullptr) {
          prevClone->next = clone;
        }
        prevClone = clone;

        clone = nullptr;
        p = p->next;
      }

      p = head;
      prevClone = nullptr;
      clone = newHead;

      while(p!=nullptr) {
        pRandom = p->random;
        if(pRandom != nullptr) {
          int rVal = pRandom->val;
          clone->random = mp[rVal];
        }

        p = p->next;
        clone = clone->next;
      }

      return newHead;        
    }
};

int main() {

  return 0;
}
