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
 

#include <iostream>
class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    std::ios_base::sync_with_stdio(0);
    ListNode *result = nullptr;
    ListNode *ptr = nullptr;
    
    int carry = 0, n1, n2, sum, digit;
    while( (l1!=nullptr) || (l2!=nullptr) ||(carry!=0) ) {
      if(l1 != nullptr) {
        n1 = l1->val;
        l1 = l1->next;
      }else{
        n1 = 0;
      }

      if(l2 != nullptr) {
        n2 = l2->val;
        l2 = l2->next;
      }else{
        n2 = 0;
      }

      sum = n1 + n2 + carry;

      carry = sum/10;
      digit = sum % 10;
      
      ListNode *currNode = new ListNode(digit);

      if(result == nullptr) {
        result = currNode;
        ptr = result;
      }else {
        ptr->next = currNode;
        ptr = ptr->next;
      }      

    }

    if(result == nullptr) {
      result = new ListNode(0);
    }

    return result;
  }

};


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

//   [9]
// [1,9,9,9,9,9,9,9,9,9]

    ListNode node1(2), node2(4), node3(3);
    ListNode node4(5), node5(6), node6(4);
    
    node1.next = &node2; node2.next = &node3;
    node4.next = &node5; node5.next = &node6;

  Solution s;
  ListNode* head = s.addTwoNumbers(&node1, &node4);

  while(head!=nullptr) {
    cout<<head->val<<" ";
    head = head->next;
  } cout<<"\n";

  while(head!=nullptr) {
    ListNode *curr = head;
    head = head->next;
    delete[] curr;
  }

  return 0;
}