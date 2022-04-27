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
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr)return nullptr;
        ListNode*temp=head;
        ListNode* prev=NULL;
        ListNode* forward=head->next;
        while(temp->next!=NULL)
        {
            temp->next=prev;
            prev=temp;
            temp=forward;
            forward=forward->next;
        }
        temp->next=prev;
        prev=temp;
        return prev;
    }
};