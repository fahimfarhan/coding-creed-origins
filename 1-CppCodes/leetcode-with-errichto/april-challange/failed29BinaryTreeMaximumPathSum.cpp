#include <bits/stdc++.h>

using namespace std;
/**
 * Definition for a binary tree node.
 */


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#define PATH_MAXIMUS first
#define BRANCH_MAXIMUS second

class Solution {
private:
    pair<int,int> calcMaximusPair(TreeNode* node) {
        if(node == nullptr){    return {0,0};    }
        pair<int,int> maximusLeft = calcMaximusPair(node->left);
        pair<int,int> maximusRight = calcMaximusPair(node->right);       

        int currPathMaximus = maximusLeft.BRANCH_MAXIMUS
                            + node->val
                            + maximusRight.BRANCH_MAXIMUS;
        int currBranchMaximus = max( (maximusLeft.PATH_MAXIMUS) , 
                                     (maximusRight.PATH_MAXIMUS) );
        if(node->val >0) {  currBranchMaximus+=node->val; }
    
        pair<int,int> newMaximus = {currPathMaximus, currBranchMaximus};
        return newMaximus;
    }

pair<int,int> calcMaximusPair2(TreeNode* node) {
    if( (node->left == nullptr) && (node->right==nullptr) ) { return{node->val, node->val};   }
    
    if(node->left == nullptr) {
        pair<int,int> maximusRight = calcMaximusPair(node->right);       

        int currPathMaximus = node->val + maximusRight.BRANCH_MAXIMUS;
        int currBranchMaximus = max( (maximusRight.PATH_MAXIMUS + node->val) , 
                                     (maximusRight.PATH_MAXIMUS) );
    
        pair<int,int> newMaximus = {currPathMaximus, currBranchMaximus};
        return newMaximus;
    }else if(node->right == nullptr) {
        pair<int,int> maximusLeft = calcMaximusPair(node->left);
        
        int currPathMaximus = maximusLeft.BRANCH_MAXIMUS + node->val;
        int currBranchMaximus = max( (maximusLeft.PATH_MAXIMUS) , 
                                     (maximusLeft.PATH_MAXIMUS + node->val) );
        
        pair<int,int> newMaximus = {currPathMaximus, currBranchMaximus};
        return newMaximus;
    }else{
        pair<int,int> maximusLeft = calcMaximusPair(node->left);
        pair<int,int> maximusRight = calcMaximusPair(node->right);       

        int currPathMaximus = maximusLeft.BRANCH_MAXIMUS
                            + node->val
                            + maximusRight.BRANCH_MAXIMUS;
        int currBranchMaximus = max( (maximusLeft.PATH_MAXIMUS) , 
                                     (maximusRight.PATH_MAXIMUS) );
        if(node->val >0) {  currBranchMaximus+=node->val; }
    
        pair<int,int> newMaximus = {currPathMaximus, currBranchMaximus};
        return newMaximus;
    }
}

public:
    int maxPathSum(TreeNode* root) {
        pair<int,int> maximusPair = calcMaximusPair2(root);
        int maximus = max(maximusPair.first, maximusPair.second);
        return maximus;
    }
};


int main() {


    return 0;
}