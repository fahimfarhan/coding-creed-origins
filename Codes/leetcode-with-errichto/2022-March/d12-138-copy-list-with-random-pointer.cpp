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
        if(head == nullptr)
          return nullptr;

        unordered_map<Node*, Node*> mp; // first = original, 2nd clone

        Node* stableHead = clone(head);
        Node* tail = stableHead;

        mp[head] = stableHead;

        Node* p = head->next;
        Node* q = nullptr;

        while(p!=nullptr) {
          q = clone(p);
          mp[p] = q;

          tail->next = q;
          tail = tail->next;
          p = p->next;
        }

        p = stableHead;

        Node* random = nullptr;
        while (p!=nullptr) {
          random = p->random;

          if(random!=nullptr) {
            p->random = mp[random];
          }
          p = p->next;
        }
        
        tail = nullptr;
        p = nullptr;
        q = nullptr;
        random = nullptr;
        
        return stableHead;
    }

    Node* clone(Node* input) {
      Node* output = new Node(input->val);
      output->random = input->random;
      return output;
    }
};


int main() {

  return 0;
}