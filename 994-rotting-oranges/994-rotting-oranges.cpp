class Solution {
public:
    bool isValid(int i,int j,vector<vector<int>>& grid)
    {
        if(i>=0 and j>=0 and i<grid.size() and j<grid[0].size() and grid[i][j]==1)return true;
        return false;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int freshOranges=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)freshOranges++;
            }
        }
        if(freshOranges==0)return 0;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
            }
        }
        int cnt=0;
        while(q.empty()==false)
        {
            int size=q.size();
            cnt++;
            while(size--)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                if(isValid(x-1,y,grid))
                {
                    grid[x-1][y]=2;
                    freshOranges--;
                    q.push({x-1,y});
                }
                 if(isValid(x+1,y,grid))
                {
                    grid[x+1][y]=2;
                      freshOranges--;
                    q.push({x+1,y});
                }
                 if(isValid(x,y-1,grid))
                {
                    grid[x][y-1]=2;
                      freshOranges--;
                    q.push({x,y-1});
                }
                 if(isValid(x,y+1,grid))
                {
                    grid[x][y+1]=2;
                      freshOranges--;
                    q.push({x,y+1});
                }
            }
        }
       if(freshOranges==0)
       {
           return cnt-1;
       }
        return -1;
    }
};