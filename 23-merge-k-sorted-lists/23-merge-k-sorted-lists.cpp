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
    ListNode* mergeTwoLists(ListNode* l1,ListNode* l2)
    {
        if(l1==NULL)return l2;
        if(l2==NULL)return l1;
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        while(l1!=NULL and l2!=NULL)
        {
            if(l1->val>l2->val)
            {
                temp->next=l2;
                l2=l2->next;
            }
            else
            {
                temp->next=l1;
                l1=l1->next;
            }
            temp=temp->next;
        }
        if(l1==NULL)temp->next=l2;
        if(l2==NULL)temp->next=l1;
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        ListNode* ans=NULL;
        for(int i=0;i<n;i++)
        {
            ans=mergeTwoLists(ans,lists[i]);
        }
        return ans;
    }
};