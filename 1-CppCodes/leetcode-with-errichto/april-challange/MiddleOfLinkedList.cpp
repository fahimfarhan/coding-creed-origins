/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int n = 0;
        ListNode* node = head;
        while(node->next!=NULL){
            n++;
            node = node->next;
        }

        int mid = (n+1)>>1;
        
        node = head;
        for(int i=0; i<mid; i++){
            node = node->next;
        }
        return node;
    }
};