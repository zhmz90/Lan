/**83. Remove Duplicates from Sorted List
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
 */

#include <iostream>

using namespace std;

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
  ListNode* deleteDuplicates(ListNode* head) {
    if (head == NULL) return head;
    ListNode* new_head=head, *curr=head, *prev=head, *tmp=NULL;
    curr = curr->next;
    while (curr != NULL){
      if (curr->val == prev->val){
        prev->next = curr->next;
        tmp = curr;
        curr = curr->next;
        delete tmp;
        continue;
      }
      prev = curr;
      curr = curr->next;
    }
    return head;
  }
};

int main(){

  return 0;
}
