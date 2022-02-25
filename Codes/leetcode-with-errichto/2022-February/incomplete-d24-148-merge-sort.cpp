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
public:
    ListNode* sortList(ListNode* head) {
      if(head == nullptr) {
        return nullptr;
      } 
      int size = getSize(head);   
    }

    ListNode* divideAndConquer(ListNode* head, int start, int end) {
      return nullptr;
    }

    ListNode* conquer() {
      return nullptr;
    }

    int getSize(ListNode* start) {
      ListNode* p = start;
      int size = 0;

      while (p!=nullptr){
        size++;
        p = p->next;
      }
      

      p = nullptr;
      return size;
    }

    ListNode* getNode(ListNode *start, int pos) {
      int i=0; 
      ListNode *p = start;
      while(i < pos) {
        p = p->next;
        i++;
      }
      return p;
    }

};

int main() {

  return 0;
}