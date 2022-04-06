class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        int area=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    area=1;
                    dfs(grid,i,j,n,m,area);
                    ans=max(ans,area);
                }
            }
        }
        return ans;
    }
    bool isValid(vector<vector<int>>& grid,int i,int j,int n,int m,int &area)
    {
        if(i>=0 and i<n and j>=0 and j<m and grid[i][j]==1)return true;
        return false;
    }
    void dfs(vector<vector<int>>& grid,int i,int j,int n,int m,int &area)
    {
        grid[i][j]=2;
        if(isValid(grid,i+1,j,n,m,area))
        {
            area++;
            dfs(grid,i+1,j,n,m,area);
        }
        if(isValid(grid,i-1,j,n,m,area))
        {
            area++;
            dfs(grid,i-1,j,n,m,area);
        }
        if(isValid(grid,i,j+1,n,m,area))
        {
            area++;
            dfs(grid,i,j+1,n,m,area);
        }
        if(isValid(grid,i,j-1,n,m,area))
        {
            area++;
            dfs(grid,i,j-1,n,m,area);
        }
    }
};