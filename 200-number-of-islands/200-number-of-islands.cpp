class Solution {
public:
    bool isValid(vector<vector<char>>& grid,int n,int m,int i,int j)
    {
        if(i>=0 and i<n and j>=0 and j<m and grid[i][j]=='1')return true;
        return false;
    }
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
                    dfs(grid,n,m,i,j);
                }
            }
        }
        return count;
    }
    void dfs(vector<vector<char>>& grid,int n,int m,int i,int j)
    {
        grid[i][j]=-1;
        if(isValid(grid,n,m,i-1,j))
        {
            dfs(grid,n,m,i-1,j);
        }
         if(isValid(grid,n,m,i+1,j))
        {
            dfs(grid,n,m,i+1,j);
        }
         if(isValid(grid,n,m,i,j-1))
        {
            dfs(grid,n,m,i,j-1);
        }
         if(isValid(grid,n,m,i,j+1))
        {
            dfs(grid,n,m,i,j+1);
        }
        
    }
};