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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count=0;
        if(head==nullptr)return head;
        if(head->next==nullptr)
        {
            if(n==0)return head;
            else
            {
                return nullptr;
            }
        }
        if(n==0)return head;
        else{
        ListNode* temp=head;
        while(temp!=nullptr)
        {
            temp=temp->next;
            count++;
        }
        cout<<count<<endl;
        int a=count-n+1;
            if(n==count)
            {
                return head->next;
            }
        ListNode* temp2=head;
        ListNode* slow=nullptr;
        ListNode* fast=nullptr;
        while(a!=1)
        {
            slow=temp2;
            temp2=temp2->next;
            fast=temp2->next;
            a--;
            
        }
        slow->next=fast;
        cout<<temp2->val<<endl;
        return head;}
    }
};