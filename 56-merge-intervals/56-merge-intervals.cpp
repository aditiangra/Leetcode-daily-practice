class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        for(int i=0;i<intervals.size();i++)
        {
            int start=intervals[i][0];//1
            int end=intervals[i][1];//3
           //if the vector is alreay present in the data structure we are not gonna push it again//
            if(ans.empty()==false){
            if(start<=ans.back()[1])
            {
                continue;
            }}
            for(int j=i+1;j<intervals.size();j++)
            {
                if(intervals[j][0]<=end)
                {
                    end=max(end,intervals[j][1]);
                }
            }
            vector<int>res;
            res.push_back(start);
            res.push_back(end);
            ans.push_back(res);
        }
        return ans;
    }
};