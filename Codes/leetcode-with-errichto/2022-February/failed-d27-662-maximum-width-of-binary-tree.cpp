#include <bits/stdc++.h>
using namespace std;


//  Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

#define ARRAY_SIZE 3005
#define PINF 5000
#define MINF -5000

class Model{
  public:
    TreeNode* node;
    int height;
    int position;

    Model(TreeNode *node, int height, int position) {
      this->node = node;
      this->height = height;
      this->position = position;
    }
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int hMax = 0;
        int currentHeight = 0;

        vector<Model> level;
        int maxWidth = 0;

        queue<Model> q;
        q.push(Model(root, 0, 1));
        while(!q.empty()) {
          auto p = q.front();
          q.pop();
          TreeNode *treeNode = p.node;
          int height = p.height;
          int pos = p.position;

          if(height > currentHeight) {
            // so we have reached a new level.
            // s1: find leftMost and rihgtMost non-null nodes
            // s2: width = right - left
            // s3: clear the vector

            int left1 = 0, right1 = 0;
            if(level.size() != 0) {
              // s1
              while(level[left1].node==nullptr) {
                left1++;
              }
              right1 = level.size() - 1;
              while(level[right1].node == nullptr) {
                right1--;
              }
              // s2
              int tempWidth = right1 - left1 + 1;
              maxWidth = max(maxWidth, tempWidth);
              // s3
              level.clear();
            }
          } 

          level.push_back(p);
          currentHeight = height;

          hMax = max(height, hMax);
          int left = pos << 1;
          int right = left | 1;
          height += 1;

          if(treeNode != nullptr) {
            q.push(Model(treeNode->left, height, left));
            q.push(Model(treeNode->right, height, right));
          }

        }  
        return maxWidth;
    }
};

/*
    int widthOfBinaryTreeV2(TreeNode* root) {
        int hMax = 0;
        int minimus[ARRAY_SIZE] = {PINF};
        int maximus[ARRAY_SIZE] = {MINF};
        for(int i=0; i<ARRAY_SIZE; i++) {
          // maxWidth = min(maxWidth, maximus[i] - minimus[i]);
          // cout<<maximus[i]<<" "<<minimus[i]<<"\n";
          minimus[i] = PINF;
          maximus[i] = MINF;
        }
        queue<Model> q;
        q.push(Model(root, 0, 1));
        while(!q.empty()) {
          auto p = q.front();
          q.pop();
          TreeNode *treeNode = p.node;
          int height = p.height;
          int pos = p.position;

          minimus[height] = min(minimus[height], pos);
          maximus[height] = max(maximus[height], pos);
          hMax = max(height, hMax);
          int left = pos << 1;
          int right = left | 1;
          height += 1;
          
          if(treeNode->left != nullptr) {
            q.push(Model(treeNode->left, height, left));
          }

          if(treeNode->right != nullptr) {
            q.push(Model(treeNode->right, height, right));
          }

        }

        int maxWidth = 0; // INT_MIN;
        int tempWidth = 0;
        for(int i=0; i<=hMax; i++) {
          tempWidth = maximus[i] - minimus[i] + 1;
          maxWidth = max(maxWidth, tempWidth);
        }
  
        return maxWidth;
    }
*/

    // int widthOfBinaryTreeV1(TreeNode* root) {
    //     int minimus[ARRAY_SIZE] = {PINF};
    //     int maximus[ARRAY_SIZE] = {MINF};
    //     for(int i=0; i<ARRAY_SIZE; i++) {
    //       // maxWidth = min(maxWidth, maximus[i] - minimus[i]);
    //       // cout<<maximus[i]<<" "<<minimus[i]<<"\n";
    //       minimus[i] = PINF;
    //       maximus[i] = MINF;
    //     }
    //     queue<Model> q;
    //     q.push(Model(root, 0, 1));
    //     while(!q.empty()) {
    //       auto p = q.front();
    //       q.pop();
    //       TreeNode *treeNode = p.node;
    //       int height = p.height;
    //       int pos = p.position;

    //       minimus[height] = min(minimus[height], pos);
    //       maximus[height] = max(maximus[height], pos);

    //       int left = pos << 1;
    //       int right = left | 1;
    //       height += 1;
          
    //       if(treeNode->left != nullptr) {
    //         q.push(Model(treeNode->left, height, left));
    //       }

    //       if(treeNode->right != nullptr) {
    //         q.push(Model(treeNode->right, height, right));
    //       }

    //     }

    //     int maxWidth = 0; // INT_MIN;
    //     int tempWidth = 0;
    //     for(int i=0; i<ARRAY_SIZE; i++) {
    //       tempWidth = maximus[i] - minimus[i];
    //       maxWidth = max(maxWidth, tempWidth);
    //     }
  
    //     return maxWidth;
    // }


int main() {
  Solution s;
  
  //   1,
  //  3,2,
  //5,3,null,9

  TreeNode n4(5);
  TreeNode n5(3), n7(9);

  TreeNode n2(3, &n4, &n5);
  TreeNode n3(3, nullptr, &n7);

  TreeNode n1(1, &n2, &n3);
  
  cout<<s.widthOfBinaryTree(&n1)<<"\n";  

  //[
  //      1
  //    3  null
  //    5 3
  TreeNode t4(5), t5(3);
  TreeNode t2(3, &t4, &t5);
  TreeNode t1(1, &t2, nullptr);

  cout<<s.widthOfBinaryTree(&t1)<<"\n";

  return 0;
}