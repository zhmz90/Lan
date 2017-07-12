/** 112. Path Sum
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
    
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct AccTreeNode{
  int acc_val;
  TreeNode* node;
  AccTreeNode(TreeNode* node,int val):node{node},acc_val{val}{}
};

class Solution {
 public:
  bool hasPathSum(TreeNode* root, int sum) {
    if (root == nullptr)  return false;
    queue<AccTreeNode*> currq, nextq;
    AccTreeNode* pacc_node;
    TreeNode *left, *right;
    currq.push(new AccTreeNode(root, root->val));
    do {
      while (!currq.empty()){
        pacc_node = currq.front();
        left = pacc_node->node->left;
        right = pacc_node->node->right;
        if (left != NULL) nextq.push( new AccTreeNode(left, left->val + pacc_node->acc_val));
        if (right != NULL)nextq.push( new AccTreeNode(right, right->val+ pacc_node->acc_val));
        if (left == NULL && right == NULL){
          if (pacc_node->acc_val == sum)
            return true;
        }
        currq.pop();
      }
      currq = nextq;
      nextq = {};
    }while(!currq.empty());
    
    return false;
  }
};


int main(){
  
  return 0;
}
