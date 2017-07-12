/**107. Binary Tree Level Order Traversal II
Given a binary tree, return the bottom-up level order traversal of its nodes' values.
(ie, from left to right, level by level from leaf to root).     
 */

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
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> ret{};
    if (root == nullptr) return ret;
    //ret.push_back({root->val});
    vector<TreeNode*> curr_nodes{}, next_nodes{};
    vector<int> vals{};
    curr_nodes.push_back(root);
    while (!curr_nodes.empty()) {
      for (auto iter=curr_nodes.begin(); iter!=curr_nodes.end(); iter++){
        vals.push_back((*iter)->val);
        if ((*iter)->left != NULL) next_nodes.push_back((*iter)->left);
        if ((*iter)->right != NULL) next_nodes.push_back((*iter)->right);
      }
      curr_nodes = next_nodes;
      next_nodes = {};
      ret.insert(ret.begin(), vals);
      vals = {};
    }
    return ret;
  }
};

