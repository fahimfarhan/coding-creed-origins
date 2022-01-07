#include <bits/stdc++.h>
using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
  ListNode* start;
  int size = 0;
public:
    Solution(ListNode* head) {
       start = head;
       ListNode* ptr = head;
       int val = 0;
       while (ptr!=nullptr) {
         val = ptr->val;
         size++;
         ptr = ptr->next;
       }
        ptr = nullptr;        
    }

    int get(int pos) {
      ListNode* ptr = start;
      for(int i=0; i<pos; i++) {
        ptr = ptr -> next;
      }
      int ret = ptr -> val;
      ptr = nullptr;
      return ret;
    }
    
    int getRandom() {
      int r = rand() % size;
      return get(r);       
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

int main() {


  return 0;
}