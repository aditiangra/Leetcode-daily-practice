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
    ListNode* mergetwolists(ListNode* l1,ListNode* l2)
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        ListNode* res1=nullptr;
        for(int i=0;i<n;i++)
        {
            res1=mergetwolists(lists[i],res1);
        }
        return res1;
    }
};