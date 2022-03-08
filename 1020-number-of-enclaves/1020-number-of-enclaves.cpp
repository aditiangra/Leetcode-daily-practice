class Solution {
public:
    bool isValid(vector<vector<int>>& grid,int i,int j,int n,int m)
    {
        if(i>=0 && i<n && j>=0 && j<m && grid[i][j]==1)
        {
            return true;
        }
        return false;
    }
    void DFS(vector<vector<int>>& grid,int i,int j,int n,int m)
    {
        grid[i][j]=0;
        if(isValid(grid,i+1,j,n,m))DFS(grid,i+1,j,n,m);
         if(isValid(grid,i-1,j,n,m))DFS(grid,i-1,j,n,m);
         if(isValid(grid,i,j+1,n,m))DFS(grid,i,j+1,n,m);
         if(isValid(grid,i,j-1,n,m))DFS(grid,i,j-1,n,m);
    }
    void resultDFS(vector<vector<int>>& grid,int i,int j,int &cnt,int n,int m)
    {
        grid[i][j]=0;
        if(isValid(grid,i+1,j,n,m))
        {
            cnt++;
            resultDFS(grid,i+1,j,cnt,n,m);
        }
          if(isValid(grid,i-1,j,n,m))
        {
            cnt++;
            resultDFS(grid,i-1,j,cnt,n,m);
        }
          if(isValid(grid,i,j+1,n,m))
        {
            cnt++;
            resultDFS(grid,i,j+1,cnt,n,m);
        }
          if(isValid(grid,i,j-1,n,m))
        {
            cnt++;
            resultDFS(grid,i,j-1,cnt,n,m);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
           int j=0;
            if(grid[i][j]==1)DFS(grid,i,j,n,m);
            j=m-1;
            if(grid[i][j]==1)DFS(grid,i,j,n,m);
        }
        for(int j=0;j<m;j++)
        {
            int i=0;
            if(grid[i][j]==1)DFS(grid,i,j,n,m);
            i=n-1;
            if(grid[i][j]==1)DFS(grid,i,j,n,m);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                resultDFS(grid,i,j,cnt,n,m);
            }
        }
        return cnt;
    }
};