/* Copyright 2017 Lanting Guo */
/** 237. Delete Node in a Linked List
Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.

*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <memory>

using std::string;
using std::vector;
using std::endl;
using std::cin;
using std::shared_ptr;
using std::make_shared;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
    void deleteNode(ListNode* node) {
      node->val = node->next->val;
      node->next = node->next->next;
    }
};


int main(int argc, char *argv[]) {
  Solution solu;
  return 0;
}
