class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool>visited(rooms.size(),false);
      dfs(visited,rooms,0);
        for(int i=0;i<visited.size();i++)
        {
            if(visited[i]==false)return false;
        }
        return true;
    }
    void dfs(vector<bool>&visited,vector<vector<int>>& rooms,int i)
    {
        visited[i]=true;
        for(int j=0;j<rooms[i].size();j++)
        {
            if(visited[rooms[i][j]]==false)
            {
                dfs(visited,rooms,rooms[i][j]);
            }
        }
    }
};