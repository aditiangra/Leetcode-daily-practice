class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    count++;
                    dfs(grid,i,j,n,m);
                }
            }
        }
        return count;
    }
    bool isValid(vector<vector<char>>& grid,int i,int j,int n,int m)
    {
        if(i>=0 and i<n and j>=0 and j<m and grid[i][j]=='1')return true;
        return false;
    }
    void dfs(vector<vector<char>>& grid,int i,int j,int n,int m)
    {
        grid[i][j]='2';
        if(isValid(grid,i-1,j,n,m)==true)
        {
            dfs(grid,i-1,j,n,m);
        }
        if(isValid(grid,i+1,j,n,m)==true)
        {
            dfs(grid,i+1,j,n,m);
        }
        if(isValid(grid,i,j-1,n,m)==true)
        {
            dfs(grid,i,j-1,n,m);
        }
        if(isValid(grid,i,j+1,n,m)==true)
        {
            dfs(grid,i,j+1,n,m);
        }
    }
};