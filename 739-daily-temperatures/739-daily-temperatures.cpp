class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> ngr(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--)
        {
            while(st.empty()==false and temperatures[st.top()]<=temperatures[i])st.pop();
            if(i<n)
            {
                if(st.empty()==false)
                {
                    ngr[i]=st.top();
                }
                else
                {
                    ngr[i]=i;
                }
            }
            st.push(i);
        }
        for(int i=0;i<n;i++)
        {
            temperatures[i]=ngr[i]-i;
        }
        return temperatures;
    }
};