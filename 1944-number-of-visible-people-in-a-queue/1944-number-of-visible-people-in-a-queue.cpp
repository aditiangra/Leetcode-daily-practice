class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
       stack<int> stk;
        vector<int> ans(heights.size(), 0);
        for(int i = heights.size()-1; i >= 0; i--){
            int count = 0;
            while(!stk.empty() && heights[stk.top()] <= heights[i]){
                stk.pop();
                count++;
            }
            if(!stk.empty())
                count++;
            ans[i] = count;
            stk.push(i);
        }
        return ans;
     
    }
};