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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      long long int number1 = 0, number2 = 0;
      ListNode *head = l1;
      ListNode *curr;

      
      long long int d = 1;
      while(head!=nullptr) {
        number1 = number1 + (head->val) * d;
        d = d * 10;
        head = head->next;
      }

      d = 1;
      head = l2;
      while(head!=nullptr) {
        number2 = number2 + (head->val) * d;
        d = d * 10;
        head = head->next;
      }

      long long int number = number1 + number2;
      // cout<<"number1 = "<<number1<<" number2 = "<<number2<<" number = "<<number<<"\n";

      head = nullptr;
      curr = nullptr;
      if(number == 0) {
        head = new ListNode(0);
        return head;
      }


      head = nullptr;
      curr = nullptr;

      while(number>0) {
        d = number%10;
        number = number/10;

        ListNode *node = new ListNode(d);
        if(head == nullptr) {
          head = node;
          curr = head;
        } else{
          curr->next = node;
          curr = curr->next;
        }
      }

      return head;
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