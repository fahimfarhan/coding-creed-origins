#include <bits/stdc++.h>
using namespace std;


// Definition for singly-linked list.
 class ListNode {
   public:
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
private:
    pair<ListNode*, ListNode*> reverseSubList(ListNode *inputHead) {
      if(inputHead == nullptr) {
        return {nullptr, nullptr};
      }
      if(inputHead->next == nullptr) {
        return {inputHead, inputHead};
      }

      pair<ListNode*, ListNode*> p = reverseSubList(inputHead->next);
      ListNode* newTail = inputHead;
      newTail->next = nullptr;
      p.second->next = newTail;
      p.second = newTail;
    
      return p;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
      if(head == nullptr) {
        return head;
      }
      // return reverseSubList(head).first;
      if(k == 1) {
        return head;
      }
      int count = 1;
      int r = 0;
      ListNode* prev = nullptr;
      ListNode* curr = head;

      for(int i=1; i<k; i++) {  // <-- this is an unusual for loop!
        cerr<<i<<" debugx\n";
        if(curr->next == nullptr) {
          return head;
        } else {
          curr = curr->next;
        }
      }

      // while(curr != nullptr) {
      //   curr = curr->next;
      //   count++;
      //   if(count == k) {
      //     break;
      //   }
      // }

      // if(count < k) {
      //   return head;
      // }

      ListNode* nextHead = curr->next;
      curr->next = nullptr;

      // printer(head);
      // cerr<<"---------\n";

      pair<ListNode*, ListNode*> p = reverseSubList(head);
      ListNode* headAfterReversingFirstList = p.first;
      ListNode* tailAfterReversingFirstList = p.second;

      ListNode* headAfterManipulatingSecondPart = reverseKGroup(nextHead, k);

      tailAfterReversingFirstList->next = headAfterManipulatingSecondPart;
      return headAfterReversingFirstList;
    }


    void printer(ListNode *head) {
        while(head!=nullptr) {
            cerr<<head->val<<" ";
            head = head->next;
        }cerr<<"\n";
    }    

};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
// 1,2,3,4,5
    ListNode n5(5);
    ListNode n4(4, &n5);
ListNode n3(3, &n4);
// ListNode n2(2, &n3);
ListNode n2(2);
ListNode n1(1, &n2);

    Solution s;
    int k = 2;

  ListNode* p = s.reverseKGroup(&n1, k);
  s.printer(p);
  return 0;
}