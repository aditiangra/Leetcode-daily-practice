class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    dfs(grid,i,j);
                    ++islands;
                }
            }
        }
        return islands;
    }
    void dfs(vector<vector<char>>& grid,int i,int j)
    {
        grid[i][j]='2';
        if(isValid(grid,i-1,j))dfs(grid,i-1,j);
        if(isValid(grid,i+1,j))dfs(grid,i+1,j);
        if(isValid(grid,i,j-1))dfs(grid,i,j-1);
        if(isValid(grid,i,j+1))dfs(grid,i,j+1);
    }
    bool isValid(vector<vector<char>>& grid,int i,int j)
    {
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size())
            return false;
        if(grid[i][j]=='2' or grid[i][j]=='0')
            return false;
        return true;
    }
};