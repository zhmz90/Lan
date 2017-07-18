/* Copyright 2017 Lanting Guo */
/** 235. Lowest Common Ancestor of a Binary Search Tree

Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5
For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.

*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <memory>
#include <utility>

using std::string;
using std::vector;
using std::endl;
using std::cin;
using std::shared_ptr;
using std::make_shared;


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      int left = p->val, right = q->val;
      if (left > right) std::swap(left, right);
      // left <= right
      int cur_val = root->val;
      while (root != nullptr) {
        if (cur_val < left) {
          root = root->right;
          cur_val = root->val;
        } else if (cur_val > right) {
          root = root->left;
          cur_val = root->val;
        } else {
          return root;
        }
      }
    }
};

int main(int argc, char *argv[]) {
  Solution solu;
  return 0;
}
