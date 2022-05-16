//0----->land 1--->water
//Approach:By calling boundary dfs remve all boundary land as it cant be an island
//then call dfs on the whole grid
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int i,j;
        for(i=0;i<n;i++)
        {
            j=0;
            if(grid[i][j]==0)boundarydfs(grid,i,j,n,m);
            j=m-1;
            if(grid[i][j]==0)boundarydfs(grid,i,j,n,m);
        }
        for(j=0;j<m;j++)
        {
            i=0;
            if(grid[i][j]==0)boundarydfs(grid,i,j,n,m);
            i=n-1;
            if(grid[i][j]==0)boundarydfs(grid,i,j,n,m);
        }
        int cnt=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                {
                    dfs(grid,i,j,n,m);
                    cnt++;
                }
            }
        }
        return cnt;
        
    }
    void dfs(vector<vector<int>>& grid,int i,int j,int n,int m)
    {
        if(i<0 or j<0 or i==n or j==m or grid[i][j]!=0)return;
        grid[i][j]=2;
        dfs(grid,i-1,j,n,m);
        dfs(grid,i+1,j,n,m);
        dfs(grid,i,j-1,n,m);
        dfs(grid,i,j+1,n,m);
    }
    void boundarydfs(vector<vector<int>>& grid,int i,int j,int n,int m)
    {
        if(i<0 or j<0 or i==n or j==m or grid[i][j]!=0)
        {
            return;
        }
        grid[i][j]=1;
        boundarydfs(grid,i-1,j,n,m);
        boundarydfs(grid,i+1,j,n,m);
        boundarydfs(grid,i,j+1,n,m);
        boundarydfs(grid,i,j-1,n,m);
    }
};