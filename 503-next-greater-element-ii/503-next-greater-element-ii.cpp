class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
         int n=nums.size();
        vector<int> nge(n);
        stack<int>st;
       
        for(int i=2*n;i>=0;i--)
        {
            while(st.empty()==false and nums[i%n]>=st.top())st.pop();
            if(i<n)
            {
                if(st.empty()==false)
                {
                    nge[i]=st.top();
                }
                else
                {
                    nge[i]=-1;
                }
            }
            st.push(nums[i%n]);
        }
        return nge;
    }
};