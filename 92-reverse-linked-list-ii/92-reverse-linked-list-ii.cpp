/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *listReverse(ListNode *head, ListNode *tailNext) {
  if (head->next == tailNext) {  //Reached the right indexed node 
    return head;
  }
  
  ListNode *p = listReverse(head->next, tailNext);
  head->next->next = head;  //Reverse the link between the head and the head of the reversed list (so far)
  head->next = tailNext;  //Instead of nullptr, we point it to the node after the right indexed node
  return p;
}
  ListNode* reverseBetween(ListNode* head, int left, int right) {
  ListNode *leftNode = head;
  int count = left;
  ListNode *leftParent = nullptr;  //Keeps track of node, just before left indexed node 
  
  //Traverse to left indexed node
  while (count > 1) {
    leftParent = leftNode;
    leftNode = leftNode->next;
    count--;
  }        
  
  //Traverse to right indexed node
  count = right;   
  ListNode *rightNode = head;
        
  while (count > 1) {
    rightNode = rightNode->next;
    count--;
  }    
  
  ListNode* revList = listReverse(leftNode, rightNode->next);

  // If the left index is the beginning of the list, nothing needs to be done 
  if (!leftParent) {
    return revList;
  }
  //Point the left indexed node's predecessor to the newly reversed list
  leftParent->next = revList;       
  return head;        
}
};