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
    ListNode* sortList(ListNode* head) {
        //is it any posibility that list is null or it is having a single element//
        if(head==nullptr or head->next==nullptr)return head;
        //single element is always sorted//
        //find the middle of ll and sort it using recursion//
        ListNode* temp=head;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next)
        {
            temp=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        temp->next=NULL;
        ListNode* l1=sortList(head);
        ListNode* l2=sortList(slow);
        return mergeList(l1,l2);
    }
    ListNode* mergeList(ListNode* l1,ListNode* l2)
    {
        if(l1==nullptr)return l2;
        if(l2==nullptr)return l1;
        ListNode* newnode=new ListNode(-1);
        ListNode* dummy=newnode;
        while(l1!=nullptr and l2!=nullptr)
        {
            if(l1->val>l2->val)
            {
                dummy->next=l2;
                l2=l2->next;
            }
            else
            {
                dummy->next=l1;
                l1=l1->next;
            }
            dummy=dummy->next;
        }
        if(l1==nullptr)
        {
            dummy->next=l2;
        }
        if(l2==nullptr)
        {
            dummy->next=l1;
        }
        return newnode->next;
    }
};