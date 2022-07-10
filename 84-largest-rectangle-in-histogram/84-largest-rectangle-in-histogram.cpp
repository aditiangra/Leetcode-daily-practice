class Solution {
public:
    vector<int> nextSmallerElement(vector<int>& heights)
    {
        vector<int>nse(heights.size());
        stack<int>st;
        for(int i=heights.size()-1;i>=0;i--)
        {
            while(st.empty()==false and heights[st.top()]>=heights[i])st.pop();
            if(i<heights.size())
            {
                nse[i]=st.empty()==false?st.top():heights.size();
            }
            st.push(i);
        }
        return nse;
    }
        vector<int> prevSmallerElement(vector<int>& heights)
    {
        vector<int>pse(heights.size());
        stack<int>st;
        for(int i=0;i<heights.size();i++)
        {
            while(st.empty()==false and heights[st.top()]>=heights[i])st.pop();
            if(i<heights.size())
            {
                pse[i]=st.empty()==false?st.top():-1;
            }
            st.push(i);
        }
        return pse;
    }
    int largestRectangleArea(vector<int>& heights) {
        //next smaller element and previous smaller element//
        int n=heights.size();
        vector<int>nse=nextSmallerElement(heights);
       // for(int i=0;i<n;i++)cout<<nse[i]<<" ";
       // cout<<endl;
         vector<int>pse=prevSmallerElement(heights);
        //for(int i=0;i<n;i++)cout<<pse[i]<<" ";
       // cout<<endl;
       int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,(nse[i]-pse[i]-1)*heights[i]);
        }
        return ans;
    }
};