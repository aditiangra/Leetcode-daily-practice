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
    ListNode* middleNode(ListNode* head) {
        if(head==nullptr)return nullptr;
         ListNode*temp=head;
        int cnt=0;
        while(temp!=NULL)
        {
            cnt++;
            temp=temp->next;
            
        }
        int n;
        if(cnt%2==0)
        {
             n=(cnt/2);
        }
        else
        {
             n=cnt/2;
        }
         ListNode*temp2=head;
        while(n!=0)
        {
            temp2=temp2->next;
            n--;
        }
        return temp2;
    }
};