#include <bits/stdc++.h>

using namespace std;

// * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *currentNode, *prevNode;        
        int n = 0;
        currentNode = node;
        while(currentNode->next != nullptr) {
            prevNode = currentNode;
            n = currentNode->next->val;
            currentNode->val = n;
            currentNode = currentNode->next;
        }
        // if(currentNode != nullptr) delete[] currentNode;
        prevNode->next = nullptr;

        currentNode = nullptr;
        prevNode = nullptr;
    }
};

int main() {

    return 0;
}