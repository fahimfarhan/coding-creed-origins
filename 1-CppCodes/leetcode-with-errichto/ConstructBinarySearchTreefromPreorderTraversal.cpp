#include <bits/stdc++.h>

using namespace std;
/**
 * @brief: I've got the faintest idea what errichto did with his O(N) soln.
 *  But I was impressed with his 1st soln (recursion) as I didnot think of that.
 * this is my version. I think it is O(N log N). N for the `for` loop, logN for the 
 * tree search and insert
 * 
*/


/**
 * Definition for a binary tree node. 
 * */
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    void insert(TreeNode *node, int m) {
        if(m < node->val) {
            // go left
            if(node->left == NULL) {
                node->left = new TreeNode(m);
            }else{
                insert((node->left), m);
            }
        }else{
            // go right
            if(node->right == NULL) {
                node->right = new TreeNode(m);
            }else{
                insert((node->right), m);
            }
        }
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size() == 0) {     return NULL;    }
        
        TreeNode *root;
        root = new TreeNode(preorder[0]);
        for(int i=1; i<preorder.size(); i++) {
            insert(root, preorder[i]);
        }
        return root;
    }
};

int main() {


    return 0;
}