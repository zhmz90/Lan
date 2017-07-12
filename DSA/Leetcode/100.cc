/** 100. Same Tree
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
 */

#include <iostream>

using namespace std;

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
  bool isSameNode(TreeNode* p, TreeNode* q){
    if (p == NULL && q == NULL) return true;
    if (p == NULL && q != NULL) return false;
    if (q == NULL && p != NULL) return false;
    if (p->val != q->val) return false;
    if (p->left==NULL  && q->left != NULL)  return false;
    if (p->right==NULL && q->right != NULL) return false;
    if (q->left==NULL  && p->left != NULL)  return false;
    if (q->right==NULL && p->right != NULL) return false;
    return true;
  }
  bool isSameTree(TreeNode* p, TreeNode* q) {
    queue<pair<TreeNode *,TreeNode *>> nodes;
    nodes.push(make_pair(p,q));
    TreeNode* n1=NULL,*n2=NULL;
    pair<TreeNode*,TreeNode*> item;
    while (!nodes.empty()){ // end ? move
      // cout<<typeid(iter).name()<<endl;
      item = nodes.front();
      n1 = item.first; n2=item.second;
      if (!isSameNode(n1, n2)) return false;
      if (n1 != NULL && n1->left != NULL) nodes.push(make_pair(n1->left,n2->left));
      if (n1 != NULL && n1->right != NULL) nodes.push(make_pair(n1->right,n2->right));
      nodes.pop();
    }
    return true;
  }
};

int main(){
  

  return 0;
}
