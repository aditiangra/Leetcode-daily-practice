class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans=0;
        int row=grid.size();
        int col=grid[0].size();
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==1)
                {ans+=4;
                if(i && grid[i-1][j]==1)ans--;
                if(i<row-1 && grid[i+1][j]==1)ans--;
                if(j && grid[i][j-1])ans--;
                if(j<col-1 && grid[i][j+1])ans--;
                }
            }
        }
        return ans;
    }
};