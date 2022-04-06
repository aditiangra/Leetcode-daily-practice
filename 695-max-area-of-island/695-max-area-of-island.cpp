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
                    bfs(grid,i,j,n,m,area);
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
    void bfs(vector<vector<int>>& grid,int i,int j,int n,int m,int &area)
    {
        queue<pair<int,int>>q;
        q.push({i,j});
        grid[i][j]=2;
        while(q.empty()==false)
        {
            auto pair=q.front();
            q.pop();
            int x=pair.first;
            int y=pair.second;
            if(isValid(grid,x-1,y,n,m,area))
            {
                area++;
                grid[x-1][y]=2;
                q.push({x-1,y});
            }
             if(isValid(grid,x+1,y,n,m,area))
            {
                area++;
                 grid[x+1][y]=2;
                q.push({x+1,y});
            }
             if(isValid(grid,x,y-1,n,m,area))
            {
                area++;
                 grid[x][y-1]=2;
                q.push({x,y-1});
            }
             if(isValid(grid,x,y+1,n,m,area))
            {
                area++;
                 grid[x][y+1]=2;
                q.push({x,y+1});
            }
        }
    }
};