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
        Node* p = interWeaveList(head);
        p = unWeaveList(p);
        return p;
    }

    Node* clone(Node* input) {
      Node* output = new Node(input->val);
      output->next = input->next;
      output->random = input->random;
      return output;
    }

    Node* interWeaveList(Node* head) {
      if(head == nullptr) {
        return nullptr;
      }

      Node* A = head;
      Node* B = nullptr;
      while(A!=nullptr) {
        Node* A1 = clone(A);
        Node* B = A->next;
        A->next = A1;
        A1->next = B;

        A = B;
        B = nullptr;
      }
      return A;
    }

    Node* unWeaveList(Node* head) {
      if(head == nullptr) {
        return nullptr;
      }

      Node* A = head; // A->A1->B->B1->... ...
      Node* A1;
      Node* B;
      Node* randomPointer = nullptr;

      Node* stableHead = head->next;

      while (A!=nullptr) {
        A1 = A->next;
        B = A1->next;

        randomPointer = A1->random;
        if(randomPointer!=nullptr) {
          A1->random = randomPointer->next;
        }

        A->next = B;
        if(B == nullptr) {
          A1->next = nullptr;
        }else {
          A1->next = B->next;
        }
        A = A->next;
      }

      A = nullptr;
      A1 = nullptr;
      B = nullptr;
      randomPointer = nullptr;
      
      return stableHead;
    }
};

int main() {

  return 0;
}