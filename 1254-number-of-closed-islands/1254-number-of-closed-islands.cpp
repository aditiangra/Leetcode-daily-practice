class Solution {
public:
    void DFS(vector<vector<int>>& grid,int i,int j,int n,int m)
    {
        grid[i][j]=1;
        if(isValid(grid,i+1,j,n,m))DFS(grid,i+1,j,n,m);
         if(isValid(grid,i-1,j,n,m))DFS(grid,i-1,j,n,m);
         if(isValid(grid,i,j+1,n,m))DFS(grid,i,j+1,n,m);
         if(isValid(grid,i,j-1,n,m))DFS(grid,i,j-1,n,m);
    }
    bool isValid(vector<vector<int>>& grid,int i,int j,int n,int m)
    {
        if(i>=0 && i<n &&j>=0 && j<m &&grid[i][j]==0)return true;
        return false;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            int j=0;
            if(grid[i][j]==0)DFS(grid,i,j,n,m);
            j=m-1;
            if(grid[i][j]==0)DFS(grid,i,j,n,m);
        }
        for(int j=0;j<m;j++)
        {
            int i=0;
            if(grid[i][j]==0)DFS(grid,i,j,n,m);
            i=n-1;
            if(grid[i][j]==0)DFS(grid,i,j,n,m);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                {
                    DFS(grid,i,j,n,m);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};