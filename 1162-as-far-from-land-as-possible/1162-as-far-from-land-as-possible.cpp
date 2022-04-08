class Solution {
public:
    bool isValid(vector<vector<int>>& grid,int x,int y)
    {
        if(x>=0 and y>=0 and x<grid.size() and y<grid[0].size() and grid[x][y]==0)return true;
        return false;
    }
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({i,j});
                }
            }
        }
        int count=0;
        while(q.empty()==false)
        {
            count++;
            int n=q.size();
            while(n--)
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
        if(count>1)
            return count-1;
        return -1;
    }
};