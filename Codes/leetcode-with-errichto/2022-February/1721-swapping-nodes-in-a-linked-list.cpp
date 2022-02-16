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
    ListNode* swapNodes(ListNode* head, int k) {
       queue<ListNode*> q;
        int count = 0;
        ListNode* curr = head;
        ListNode* p1 = nullptr;
        ListNode* p2 = nullptr;

        while(curr!=nullptr) {
            if(q.size() == k) {
                q.pop();
            }
            q.push(curr);
            count++;
            if(count == k) {
                p1 = curr;
            }
            curr = curr->next;
        }

        if(count == 1 || count < k) {
            return head;
        }

        p2 = q.front();
  
        cerr<<p1->val<<" "<<p2->val<<"\n";
  
        if(p1->val != p2->val) {
            p1->val = p1->val ^ p2->val;
            p2->val = p1->val ^ p2->val;
            p1->val = p1->val ^ p2->val;
        }
    
        return head;
    }

    void printer(ListNode *head) {
        while(head!=nullptr) {
            cout<<head->val<<" ";
            head = head->next;
        }cout<<"\n";
    }
};

int main() {
// 1,2,3,4,5
    ListNode n5(5);
    ListNode n4(4, &n5);
ListNode n3(3, &n4);
ListNode n2(2, &n3);
ListNode n1(1, &n2);

    Solution s;
    int k = 2;
    ListNode* res = s.swapNodes(&n1, k);
    s.printer(res);
    return 0;
}

