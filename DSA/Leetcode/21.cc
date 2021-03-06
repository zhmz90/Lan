/** 21. Merge Two Sorted Lists
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
 */

#include <iostream>
#include <vector>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;
    ListNode* head, *curr;
    if (l1->val<=l2->val){
      curr = l1;
      l1 = l1->next;
    }
    else{
      curr = l2;
      l2 = l2->next;
    }
    head = curr;
    
    while (l1!=NULL && l2!=NULL){
      if (l1->val<=l2->val){
        curr->next = l1;
        l1 = l1->next;
      }
      else{
        curr->next = l2;
        l2 = l2->next;
      }
      curr = curr->next;
    }
    if (l1 == NULL) curr->next = l2;
    if (l2 == NULL) curr->next = l1;
    
    return head;
  }
};

int main(){
  Solution solu;

  return 0;
}
