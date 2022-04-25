class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        for(int i=0;i<intervals.size();i++)
        {
            if(ans.empty()==true)
            {
                vector<int>res;
                res.push_back(intervals[0][0]);
                 res.push_back(intervals[0][1]);
                ans.push_back(res);
            }
            else if(ans.back()[1]>=intervals[i][0])
            {
                ans.back()[1]=max(ans.back()[1],intervals[i][1]);
            }
            else if(ans.back()[1]<intervals[i][0]) 
            {
                 vector<int>res;
                res.push_back(intervals[i][0]);
                 res.push_back(intervals[i][1]);
                ans.push_back(res);
            }
        }
        return ans;
    }
};