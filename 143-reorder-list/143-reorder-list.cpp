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
    void reorderList(ListNode* head) {
        if(head==NULL or head->next==NULL or head->next->next==NULL)return;
        stack<ListNode*>st;
        int size=0;
        ListNode* ptr=head;
        while(ptr!=NULL)
        {
            st.push(ptr);
            size++;
            ptr=ptr->next;
        }
        ListNode* pptr=head;
        for(int j=0;j<size/2;j++)
        {
            ListNode* element=st.top();
            st.pop();
            element->next=pptr->next;
            pptr->next=element;
            pptr=pptr->next->next;
        }
        pptr->next=NULL;
    }
};