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
    ListNode* reverse(ListNode* head)
    {
        if(head==NULL or head->next==NULL)return head;
        ListNode* rest=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return rest;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head=new ListNode(0);
        ListNode* temp=head;
        if(l1==NULL)return l2;
        if(l2==NULL)return l1;
        l1=reverse(l1);
        l2=reverse(l2);
        int carry=0;
        while(l1!=NULL or l2!=NULL or carry)
        {
            int sum=0;
            if(l1!=NULL)
            {
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL)
            {
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            carry=sum/10;
            ListNode* dummy=new ListNode(sum%10);
            temp->next=dummy;
            temp=temp->next;
        }
        head=reverse(head->next);
        return head;
    }
};