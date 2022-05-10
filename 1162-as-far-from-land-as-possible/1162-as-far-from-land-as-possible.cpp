//use of multisource dfs//
class Solution {
public:
    bool isValid(vector<vector<int>>& grid,int i,int j)
    {
        if(i>=0 and j>=0 and i<grid.size() and j<grid[0].size() and grid[i][j]==0)return true;
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
        int ant=0;
        while(q.empty()==false)
        {
            ant++;
            int n=q.size();
            
            for(int i=0;i<n;i++)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                if(isValid(grid,x-1,y))
                {q.push({x-1,y});
                 grid[x-1][y]=1;
                }
                 if(isValid(grid,x+1,y))
                {q.push({x+1,y});
                 grid[x+1][y]=1;
                }
                 if(isValid(grid,x,y-1))
                {q.push({x,y-1});
                 grid[x][y-1]=1;
                }
                 if(isValid(grid,x,y+1))
                {q.push({x,y+1});
                 grid[x][y+1]=1;
                }
            }
        }
        if(ant>1)return ant-1;
        return -1;
        
    }
};