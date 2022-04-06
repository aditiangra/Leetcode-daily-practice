class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>nsr(n);
        vector<int>nsl(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--)
        {
            while(st.empty()==false and heights[st.top()]>=heights[i])st.pop();
            if(i<n)
            {
                if(st.empty()==false)
                {
                    nsr[i]=st.top();
                }
                else
                {
                    nsr[i]=n;
                }
            }
            st.push(i);
        }
        while(st.empty()==false)st.pop();
           for(int i=0;i<n;i++)
        {
            while(st.empty()==false and heights[st.top()]>=heights[i])st.pop();
            if(i<n)
            {
                if(st.empty()==false)
                {
                    nsl[i]=st.top();
                }
                else
                {
                    nsl[i]=-1;
                }
            }
            st.push(i);
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,((nsr[i]-nsl[i]-1)*heights[i]));
        }
        return ans;
        
    }
};