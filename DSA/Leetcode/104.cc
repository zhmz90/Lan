/**104. Maximum Depth of Binary Tree
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Node {
  TreeNode* node;
  int depth;
  Node(TreeNode* root, int depth):node{root},depth{depth}{}
};
class Solution {
 public:
  int maxDepth(TreeNode* root) {
    if (root == NULL) return 0;
    queue<Node*> nodes;
    nodes.push( new Node(root, 1));
    int max_depth=1, curr_depth=1;
    TreeNode* left=NULL, *right=NULL;
    Node* item{NULL};
    while (!nodes.empty()){
      item = nodes.front();
      if (item->node == NULL) {nodes.pop(); continue;}
      left  = item->node->left;
      right = item->node->right;
      curr_depth = item->depth;
      if (left != NULL) nodes.push(new Node(left, curr_depth+1));
      if (right != NULL) nodes.push(new Node(right, curr_depth+1));
      if (curr_depth > max_depth) max_depth=curr_depth;
      nodes.pop();
    }
    return max_depth;
  }
};

int main(){
  TreeNode* root = new TreeNode(1);
  root->right = new TreeNode(2);
  Solution solu;
  cout<<solu.maxDepth(root)<<endl;
  
  return 0;
}
