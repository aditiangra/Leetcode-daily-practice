/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA=headA;
        ListNode* tempB=headB;
        while(tempA!=NULL)
        {
            while(tempB!=NULL)
            {
                   if(tempA==tempB)
                   {
                       return tempA;
                   }
                tempB=tempB->next;
            }
            tempB=headB;
            tempA=tempA->next;
        }
        return NULL;
    }
};