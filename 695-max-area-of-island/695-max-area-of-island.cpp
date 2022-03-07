class Solution {
public:
    bool isValid(vector<vector<int>>&grid,int i,int j,int m,int n)
    {
        if(i>=0 && i<n && j>=0 && j<m &&grid[i][j]==1)return true;
        return false;
    }
    void DFS(vector<vector<int>>&grid,int i,int j,int m,int n,int &area)
    {
        area++;
        grid[i][j]=0;
        if(isValid(grid,i+1,j,m,n)==true)DFS(grid,i+1,j,m,n,area);
         if(isValid(grid,i-1,j,m,n)==true)DFS(grid,i-1,j,m,n,area);
         if(isValid(grid,i,j-1,m,n)==true)DFS(grid,i,j-1,m,n,area);
         if(isValid(grid,i,j+1,m,n)==true)DFS(grid,i,j+1,m,n,area);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    int area=0;
                    DFS(grid,i,j,m,n,area);
            
                    ans=max(ans,area);
                }
            }
        }
        return ans;
    }
    
    
};