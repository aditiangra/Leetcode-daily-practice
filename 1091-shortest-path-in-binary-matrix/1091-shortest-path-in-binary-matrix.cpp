class Solution {
public:
    bool isValid(vector<vector<int>>& grid,int i,int j)
    {
        if(i>=0 and j>=0 and i<grid.size() and j<grid[0].size() and grid[i][j]==0)return true;
        return false;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]!=0)return -1;
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        q.push({0,0});
        int steps=0;
        while(q.empty()==false)
        {
            int size=q.size();
            steps++;
            while(size--)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                if(x==n-1 and y==m-1)return steps;
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
                  if(isValid(grid,x-1,y+1))
                {
                    q.push({x-1,y+1});
                    grid[x-1][y+1]=1;
                }
                  if(isValid(grid,x+1,y+1))
                {
                    q.push({x+1,y+1});
                    grid[x+1][y+1]=1;
                }
                  if(isValid(grid,x+1,y-1))
                {
                    q.push({x+1,y-1});
                    grid[x+1][y-1]=1;
                }
                  if(isValid(grid,x-1,y-1))
                {
                    q.push({x-1,y-1});
                    grid[x-1][y-1]=1;
                }
            }
          
        }
        
        return -1;
    }
};