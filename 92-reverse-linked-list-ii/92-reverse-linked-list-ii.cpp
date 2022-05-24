class Solution {
private:
    ListNode* successor;
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == 1)
            return reverseFirstN(head, right);
        
        head->next = reverseBetween(head->next, left - 1, right - 1);
        return head;
    }
    
    ListNode* reverseFirstN(ListNode* head, int firstN) {
        if(firstN == 1) {
            successor = head->next;
            return head;
        }
        
        ListNode* last = reverseFirstN(head->next, firstN - 1);
        
        head->next->next = head;
        head->next = successor;
        
        return last;
    }
};