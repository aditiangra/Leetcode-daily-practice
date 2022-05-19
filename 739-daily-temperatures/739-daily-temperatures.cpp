class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
          int n=temperatures.size();
        stack<pair<int,int>>st;//index,arr[index]//
        vector<int> answer(n);
      
        for(int i=n-1;i>=0;i--)
        {
            while(st.empty()==false and st.top().second<=temperatures[i])st.pop();
            if(i<n)
            {
                if(st.empty()==false )answer[i]=st.top().first;
                else answer[i]=i;
            }
            st.push({i,temperatures[i]});
        }
        for(int i=0;i<n;i++)
        {
            answer[i]=answer[i]-i;
        }
        return answer;
    }
};