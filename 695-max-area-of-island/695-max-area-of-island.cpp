class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int res=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    int count=0;
                    dfs(grid,i,j,count);
                    res=max(res,count);
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<int>>& grid,int i,int j,int &count)
    {
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or grid[i][j]==0)
            return;
        count++;
        grid[i][j]=0;
        dfs(grid,i-1,j,count);
        dfs(grid,i+1,j,count);
        dfs(grid,i,j-1,count);
        dfs(grid,i,j+1,count);
    }
};