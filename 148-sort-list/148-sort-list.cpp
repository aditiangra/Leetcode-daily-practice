class Solution {
public:
    
    ListNode* merge(ListNode* left, ListNode* right){
        
        ListNode* head = NULL;
        ListNode* tail = NULL;
        
        while(left != NULL && right != NULL){
            if(left->val <= right->val){
                if(head == NULL){
                    head = left;
                    tail = left;
                }
                else{
                    tail->next = left;
                    tail = tail->next;
                }
                left = left->next;
            }
            else{
                if(head == NULL){
                    head = right;
                    tail = right;
                }
                else{
                    tail->next = right;
                    tail = tail->next;
                }
                right = right->next;
            }
        }
        
        if(left != NULL){
            tail->next = left;
        }
        
        if(right != NULL){
            tail->next = right;
        }
        
        return head;
    }
    
    ListNode* mergeSort(ListNode* head){
        
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while( fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        fast = slow->next;
        
        slow->next = NULL;
        
        ListNode* left = mergeSort(head);
        ListNode* right = mergeSort(fast);

        return merge(left, right);
        
    }
    
    
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};