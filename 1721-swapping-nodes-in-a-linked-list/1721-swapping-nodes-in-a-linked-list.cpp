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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *first=head;
        ListNode *last=head;
        int count=0;
        while(first!=NULL)
        {
            
            count++;
            first=first->next;
        }
        first=head;
      
        int n=count-k+1;
          while(k!=1)
        {
           
            k--;
            first=first->next;
        }
        cout<<n;
        while(n!=1)
        {
          
            n--;
            last=last->next;
        }
        swap(first->val,last->val);
       
        return head;
    }
};