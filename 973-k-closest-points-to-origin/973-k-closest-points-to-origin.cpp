class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>>pq;
        for(int i=0;i<points.size();i++)
        {
            pq.push({points[i][0]*points[i][0]+points[i][1]*points[i][1],{points[i][0],points[i][1]}});
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
         vector<vector<int>>result;
        while(pq.size()>0)
        {
            auto it=pq.top();
            pq.pop();
            result.push_back(it.second);
        }
        return result;
    }
};