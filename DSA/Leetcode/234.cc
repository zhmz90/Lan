/* Copyright 2017 Lanting Guo */
/** 234. Palindrome Linked List
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <utility>

using std::string;

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
    bool isPalindrome(ListNode* head) {
      size_t len = 0;
      ListNode* it = head;
      while (it != nullptr) {
         // cout<<it<< " ";
        len += 1;
        it = it->next;
      }
       // cout<<endl;
      if (len <= 1) return true;
      ListNode *left = head, *right = head->next, *tmp = nullptr;
      left->next = nullptr;
      if (len == 2) {
        if (left->val == right->val)
          return true;
        else
          return false;
      }
      if (len == 3) {
        if (left->val == right->next->val)
          return true;
        else
          return false;
      }
      auto mid = len / 2;
      bool isOdd = len % 2;
      size_t i = 0;
      //  cout<<len << "right: "<<right<<right->val<<" "<<left->val<<endl;
      while (right != nullptr) {
          //cout<<len << " "<<right->val<<" "<<left->val<<endl;
        i += 1;
        tmp = left;
          //cout<<"tmp: "<<tmp->val<<endl;
        left = right;
          //cout<<"left: "<<left->val<<endl;
          right = right->next;
        left -> next = tmp;
         // cout<<"left: "<<left->val<<endl;
        
          //cout<<"right: "<<right<<right->val<<endl;
        if (i == mid-1) break;
      }
       // cout<<len << " "<<right->val<<" "<<left->val<<endl;
       // cout<<isOdd<<endl;
      if (isOdd) right = right->next;
      while (right != nullptr) {
          //cout<<len << " "<<right->val<<" "<<left->val<<endl;
        if (right->val != left->val) {
            //cout<<right->val<<endl;
            //cout<<left->val<<endl;
            //cout<<isOdd<<endl;
          return false;
        }
         //cout<<right->val<<endl;
        right = right->next;
        left  = left ->next;
      }
      return true;
    }
};

int main(int argc, char *argv[]) {
  Solution solu;
  return 0;
}
