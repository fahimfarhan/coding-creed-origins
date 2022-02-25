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

    Node *unWeaveList(Node *head) {
      if(head == nullptr) {
        return nullptr;
      }
      Node *newHead = head->next;
      Node *p = newHead;
      Node *q = nullptr;

      while (p!=nullptr) {
        q = p->next;
        if(q !=nullptr) {
          q = q->next;
        }
        p->next = q;
      }

      return newHead;
    }

    Node *interWeaveList(Node* head) {
      if(head == nullptr) {
        return nullptr;
      }  

      int pVal = 0;
      Node *p = head;
      Node *pClone, *q;
      while(p != nullptr) {
        q = p->next;
        pVal = p->val;
        pClone = new Node(pVal);
        p->next = pClone;
        pClone->next = q;

        pClone->random = p->random;
        p = q;
        q = nullptr;
      }

      p = head->next;

      Node *pCloneRandom = nullptr;
      while (p!=nullptr){
        if(p->random == nullptr) {
          pCloneRandom = nullptr;
        } else {
          pCloneRandom = p->random->next;
        }
        p->random = pCloneRandom;
        p = p->next;
        if(p!=nullptr) {
          p = p->next;
        }
      }
      
      return head;
    }


    Node* copyRandomList(Node* head) {
      if(head == nullptr) {
        return nullptr;
      }  

      Node *p = interWeaveList(head);
      p = unWeaveList(p);
      return p;
    }
};


int main() {

  return 0;
}
