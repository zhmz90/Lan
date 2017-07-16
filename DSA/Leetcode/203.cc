/* Copyright 2017 Lanting Guo */
/** 203. Remove Linked List Elements
    
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using string = std::string;

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
    ListNode* removeElements(ListNode* head, int val) {
      ListNode* new_head = head, *curr, *tmp;
      while (head != nullptr && head->val == val) {
        new_head = head->next;
        tmp = head;
        head = head->next;
        //  delete tmp;
      }
      if (new_head == nullptr) return new_head;
      curr = head;
      while (curr->next != nullptr) {
        if (curr->next->val == val) {
          tmp = curr->next;
          curr->next = tmp->next;
          continue;
          //  delete tmp;
        }
        curr = curr->next;
      }
      return new_head;
    }
};


int main(int argc, char *argv[]) {
  Solution solu;
  return 0;
}
