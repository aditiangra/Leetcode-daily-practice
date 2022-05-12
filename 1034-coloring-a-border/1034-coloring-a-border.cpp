class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int n=grid.size();
        int m=grid[0].size();
        int oldcolor=grid[row][col];
        dfs(grid,row,col,oldcolor);
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]<0)
                {
                    grid[i][j]=color;
                }
            }
        }
        return grid;
    }
    void dfs(vector<vector<int>>& grid, int row, int col, int oldcolor)
    {
        if(row<0 || row>=grid.size() || col<0 || col>=grid[0].size() || grid[row][col]!=oldcolor)return;
        grid[row][col]=-oldcolor;
        dfs(grid,row-1,col,oldcolor);
        dfs(grid,row+1,col,oldcolor);
        dfs(grid,row,col-1,oldcolor);
        dfs(grid,row,col+1,oldcolor);
        if(row>0 && row<grid.size()-1 && col>0 && col<grid[0].size()-1 && abs(grid[row-1][col])==oldcolor && abs(grid[row+1][col])==oldcolor && abs(grid[row][col-1])==oldcolor && abs(grid[row][col+1])==oldcolor)
        {
            grid[row][col]=oldcolor;
        }
    }
};