class Solution{
    typedef pair<int,pair<int,int>>ppi;
public:
    bool isValid(int i,int j,vector<vector<int>>& heights)
    {
        if(i<0 or j<0 or i>=heights.size() or j>=heights[0].size())return false;
        return true;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        priority_queue<ppi,vector<ppi>,greater<ppi>>pq;
        vector<vector<int>> effort(n,vector<int>(m,INT_MAX));
        
        pq.push({0,{0,0}});
        while(pq.empty()==false)
        {
            int eff=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();
            if(i==n-1 and j==m-1)return eff;
            if(eff>=effort[i][j])continue;
            effort[i][j]=eff;
            if(isValid(i+1,j,heights))
            {
                int ne=max(eff,abs(heights[i][j]-heights[i+1][j]));
                pq.push({ne,{i+1,j}});
            }
               if(isValid(i-1,j,heights))
            {
                int ne=max(eff,abs(heights[i][j]-heights[i-1][j]));
                pq.push({ne,{i-1,j}});
            }
               if(isValid(i,j-1,heights))
            {
                int ne=max(eff,abs(heights[i][j]-heights[i][j-1]));
                pq.push({ne,{i,j-1}});
            }
               if(isValid(i,j+1,heights))
            {
                int ne=max(eff,abs(heights[i][j]-heights[i][j+1]));
                pq.push({ne,{i,j+1}});
            }
        }
        return -1;
    }
};