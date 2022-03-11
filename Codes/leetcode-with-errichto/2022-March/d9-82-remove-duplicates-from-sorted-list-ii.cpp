#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
    int *kount;

public:
  ListNode* deleteDuplicates(ListNode* head) {
    if(head == nullptr) { return nullptr; }

    kount = new int[205];
    for(int i=0; i<205; i++) {
      kount[i] = 0;
    }

    ListNode *p = head;
    while (p!=nullptr) {
      /* code */
      kount[ (p->val + 100) ]++;
      p = p->next;
    }

    ListNode *ret = nullptr;
    ListNode *q = nullptr;
    p = head;

    while (p!=nullptr) {
      /* code */
      if(kount[p->val+100] == 1) {
        if(ret == nullptr) {
          ret = new ListNode(p->val);
          q = ret;
        } else {
          q->next = new ListNode(p->val);
          q = q->next;
        }

      }
      p = p->next;
    }

    delete[] kount;
    p = nullptr;
    q = nullptr;

    return ret;
  }
};

int main() {

  return 0;
}