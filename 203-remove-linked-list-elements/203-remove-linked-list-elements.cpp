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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* current = head;
        ListNode* previous = head;
        if(head==nullptr) 
        {
            return head;
        }
        while(head!=nullptr && head->val==val)
        {
            head = head->next;
        }
       
        while(current!=nullptr){
            if(current->val==val)
            {
                previous->next = current->next;
                current = current->next;
            }
            else{
                previous = current;
                current = current->next;        
            }
        }
        return head;
    }
};