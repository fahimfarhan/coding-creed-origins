/**
 * @file d27-662-maximum-width-of-binary-tree.cpp
 * @author your name (you@domain.com)
 * @brief Special thanks to https://wentao-shao.gitbook.io/leetcode/binary-tree/662.maximum-width-of-binary-tree#approach-1-dfs
 * @version 0.1
 * @date 2022-02-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>
using namespace std;


  // Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


#define ARRAY_SIZE 3005
#define ll unsigned long long int

class Solution {
public:
    ll width = 0;
    unordered_map<ll, ll> mpLeft; // O(NLogN)
    // int mpLeft[ARRAY_SIZE] = {0};      // O(1)  // not working :/  // almost sob kota node left e, evabe straight line banais. okhane crash kortise maybe

    int widthOfBinaryTree(TreeNode* root) {  
      dfs(root, 0, 1);
      return (int)width;
    }

    void dfs(TreeNode *node, ll height, ll pos) {
      if(node == nullptr) {
        return;
      }

      if(!mpLeft[height]) {
        mpLeft[height] = pos;
      }

      ll rightPos = pos;
      ll leftPos = mpLeft[height];
      ll tempWidth = rightPos - leftPos + 1;
      width = max(width, tempWidth);

      ll left = pos << 1;
      ll right = left | 1;
      ll nextHeight = height + 1;
      dfs(node->left, nextHeight, left);
      dfs(node->right, nextHeight, right);
    }
};

int main() {

  return 0; 
}