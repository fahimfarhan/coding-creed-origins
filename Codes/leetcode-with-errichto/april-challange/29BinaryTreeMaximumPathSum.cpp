#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
    int answer;
    int dfs(TreeNode *node) {
        if(node == NULL) return 0;

        int x = dfs(node->left);
        int y = dfs(node->right);
        answer = max(answer, x + y + node->val);
        return max(0, max(x,y) + node->val);
    }
public:
    int maxPathSum(TreeNode* root) {
        answer = INT_MIN;
        dfs(root);
        return answer;
    }
};

int main() {


    return 0;
}