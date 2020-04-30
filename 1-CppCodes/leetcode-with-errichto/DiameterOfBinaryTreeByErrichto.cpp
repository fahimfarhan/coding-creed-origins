#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
    // @brief: diameter, depth
    pair<int, int> dfs(TreeNode* root) {
        if(root == NULL) {
            return {0,0};
        }
        pair<int,int> left = dfs(root->left);
        pair<int,int> right = dfs(root->right);

        int diam = max(left.first, right.first, left.second + right.second);
        return {diam, max(left.second, right.second) + 1 };
    } 

    int diameterOfBinaryTree(TreeNode* root) {
        return dfs(root).first;
    }
};

int main() {

    return 0;
}

/*
3 cases:
longestPathAtRoot = 
    1. longestPathAtLeftSubTree  OR
    2. longestPathInRightSubTree OR
    3. goes through the root. so deepest leaf in leftSubTree + deepest leaf in rightSubTree

    Therefore, we need a method that returns a pair <current diameter, maxDepth>

MaxDepthAtCurrentNode = max(depthAtLEftSubTree, depthAtRightSubTree) + 1 

*/