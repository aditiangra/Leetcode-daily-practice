class Solution {
public:
    bool isValid(vector<vector<int>>& grid,int i,int j)
    {
        if(i>=0 and j>=0 and i<grid.size() and j<grid[0].size() and grid[i][j]==0)return true;
        return false;
    }
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)q.push({i,j});
            }
        }
        int cnt=0;
        while(q.empty()==false)
        {
            cnt++;
            int n=q.size();
            for(int k=0;k<n;k++)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                if(isValid(grid,x-1,y))
                {
                    q.push({x-1,y});
                    grid[x-1][y]=1;
                }
                  if(isValid(grid,x+1,y))
                {
                    q.push({x+1,y});
                       grid[x+1][y]=1;
                }
                  if(isValid(grid,x,y-1))
                {
                    q.push({x,y-1});
                       grid[x][y-1]=1;
                }
                  if(isValid(grid,x,y+1))
                {
                    q.push({x,y+1});
                       grid[x][y+1]=1;
                }
            }
        }
        if(cnt>1)return cnt-1;
        return -1;
    }
};