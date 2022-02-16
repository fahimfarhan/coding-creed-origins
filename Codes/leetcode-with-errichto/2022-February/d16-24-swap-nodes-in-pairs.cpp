#include <bits/stdc++.h>
using namespace std;

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
  class ListNode {
		public:
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
			ListNode* prev = nullptr;
			ListNode* curr = head;
			int count = 0;
			while(curr!=nullptr) {
				prev = curr;
				curr = curr->next;
				count++;

				if( ((count&1) == 1) && (curr != nullptr) ) {
					prev->val = prev->val ^ curr->val;
					curr->val = prev->val ^ curr->val;
					prev->val = prev->val ^ curr->val;
				}
			}
			return head;
    }
};

int main() {
	return 0;
}
