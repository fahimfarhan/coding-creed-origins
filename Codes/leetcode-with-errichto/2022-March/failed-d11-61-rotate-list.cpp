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
private:
  queue<int> q;

public:
    int getSize(ListNode *tail) {
      int N = 0;
      while (tail!=nullptr) {
        N++;
        tail = tail->next;
      }
      return N;
    }

    ListNode* rotateRight(ListNode* head, int k1) {
      ListNode *tail = head;
      int N = 0;
      while (tail->next!=nullptr) {
        N++;
        tail = tail->next;
      }
      
      tail->next = head;
      int k = k1 % N;

      int j = 0;
      for(int i=1; i<=k; i++) {
        j--;
        if(j == -1) { j = N-1;  }
      }


      ListNode* newTail = head; //parent[j];
      
      for(int i=9; i<j; i++) {
        newTail = newTail->next;
      }

      ListNode* newHead = newTail->next;

      newTail->next = nullptr;
      return newHead;  
    }
};

void printer(ListNode* p) {
  while(p!=nullptr) {
    cout<<p->val<<" -> ";
    p = p->next;
  }cout<<"\n";
}

void foo1() {
  ListNode two(2);
  ListNode one(1, &two);

  Solution s;
  ListNode *p = s.rotateRight(&one, 1);
  printer(p);
  
}


void foo2() {
  ListNode three(2);
  ListNode two(1, &three);
  ListNode one(0, &two);

  Solution s;
  ListNode *p = s.rotateRight(&one, 1);
  printer(p);
}

void foo4() {
  ListNode three(2);
  ListNode two(1, &three);
  ListNode one(0, &two);

  Solution s;
  ListNode *p = s.rotateRight(&one, 4);
  printer(p);
}


void foo3() {
  ListNode five(5);
  ListNode four(4, &five); 
  ListNode three(3, &four);
  ListNode two(2, &three);
  ListNode one(1, &two);

  Solution s;
  ListNode *p = s.rotateRight(&one, 2);
  printer(p);
}


int main() {
  foo1(); 
  foo2();
  foo4();
  foo3();
  return 0;
}
