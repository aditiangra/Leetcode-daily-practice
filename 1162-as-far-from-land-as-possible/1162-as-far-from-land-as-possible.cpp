class Solution {
public:
    bool isValid(int i,int j,vector<vector<int>>& grid)
    {
        if(i>=0 and j>=0 and i<grid.size() and j<grid[0].size() and grid[i][j]==0)return true;
        return false;
    }
    int maxDistance(vector<vector<int>>& grid) {
        //0->water//
        //1->land//
        //multisource bfs//
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({i,j});
                }
            }
        }
        int ans=0;
        while(q.empty()==false)
        {
            ans++;
            int s=q.size();
            while(s--)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                if(isValid(x-1,y,grid))
                {
                    grid[x-1][y]=1;
                    q.push({x-1,y});
                }
                if(isValid(x+1,y,grid))
                {
                    grid[x+1][y]=1;
                    q.push({x+1,y});
                }
                if(isValid(x,y-1,grid))
                {
                    grid[x][y-1]=1;
                    q.push({x,y-1});
                }
                if(isValid(x,y+1,grid))
                {
                    grid[x][y+1]=1;
                    q.push({x,y+1});
                }
                
            }
        }
        if(ans>1)return ans-1;
        return -1;
        
    }
};