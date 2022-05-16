class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr)return head;
        ListNode* temp=head;
       
        while(temp!=NULL)
        {
            while(temp->next!=NULL and temp->next->val==temp->val)temp->next=temp->next->next;
           
            temp=temp->next;
          
            
        }
        return head;
    }
};