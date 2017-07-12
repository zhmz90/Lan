/** 111. Minimum Depth of Binary Tree
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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

class Solution {
 public:
  int minDepth(TreeNode* root) {
    if (root==NULL) return 0;
    queue<TreeNode *> currq;
    queue<TreeNode *> nextq;
    TreeNode* pnode;
    int depth=1;
    currq.push(root);
    while (true){
      while (!currq.empty()){
        pnode = currq.front();
        if (pnode->left != NULL) nextq.push(pnode->left); 
        if (pnode->right != NULL) nextq.push(pnode->right);
        if (pnode->left == NULL && pnode->right==NULL){
          return depth;
        }
        currq.pop();
      }
      currq = nextq;
      nextq = {};
      depth++;      
    }

  }
};


int main(){
  
  return 0;
}
