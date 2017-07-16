/* Copyright 2017 Lanting Guo */
/** 206. Reverse Linked List
    
Reverse a singly linked list.

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
    ListNode* reverseList(ListNode *head) {
      if (head == nullptr) return head;
      ListNode *prev = nullptr, *curr = head, *next = head->next;
      while (next != nullptr) {
        curr->next = prev;
        prev = curr;
        curr = next;
        next = next->next;
      }
      curr->next = prev;
      return curr;
    }
};

int main(int argc, char *argv[]) {
  Solution solu;
  return 0;
}
