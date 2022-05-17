class Solution {
public:
    bool isBorder(vector<vector<char>>&maze,int i,int j,int x,int y)
    {
        if((i==0 or j==0 or i==maze.size()-1 or j==maze[0].size()-1) and (i!=x or j!=y))return true;
        return false;
    }
    bool isValid(vector<vector<char>>& maze,int i,int j)
    {
        if(i>=0 and j>=0 and i<maze.size() and j<maze[0].size() and maze[i][j]=='.')return true;
        return false;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n=maze.size();
        int m=maze[0].size();
        queue<pair<int,int>>q;
        q.push({entrance[0],entrance[1]});
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
                if(isBorder(maze,x,y,entrance[0],entrance[1]))return ans-1;
                if(isValid(maze,x-1,y))
                {
                    maze[x-1][y]='*';
                    q.push({x-1,y});
                }
                  if(isValid(maze,x+1,y))
                {
                    maze[x+1][y]='*';
                    q.push({x+1,y});
                }
                  if(isValid(maze,x,y-1))
                {
                    maze[x][y-1]='*';
                    q.push({x,y-1});
                }
                  if(isValid(maze,x,y+1))
                {
                    maze[x][y+1]='*';
                    q.push({x,y+1});
                }
            }
        }
        return -1;
    }
};