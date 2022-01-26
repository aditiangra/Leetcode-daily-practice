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
    int pairSum(ListNode* head) {
        int sum=INT_MIN;
        vector<int>ans;
        ListNode* node=head;
        while(node!=nullptr)
        {
            ans.push_back(node->val);
            node=node->next;
        }
        int i=0;
        int j=ans.size()-1;
        while(i<=j)
        {
            sum=max((ans[i]+ans[j]),sum);
            i++;
            j--;
        }
        return sum;
    }
};