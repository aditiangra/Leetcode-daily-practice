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
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* temp=head;
        int cnt=0;
        vector<int>arr;
        while(temp!=NULL)
        {
            cnt++;
            arr.push_back(temp->val);
            temp=temp->next;
        }
        vector<int> nge(cnt);
         stack<long long>st;
        for(int i=cnt-1;i>=0;i--)
        {
            while(st.empty()==false and st.top()<=arr[i])st.pop();
            if(i<cnt)
            {
                nge[i]=st.empty()==false?st.top():0;
            }
            st.push(arr[i]);
        }
        return nge;
        
    }
};