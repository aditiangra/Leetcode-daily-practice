class Solution {
public:
   void dfs(int src,vector<vector<int>>&rooms,vector<bool>&visited)
    {
        visited[src]=true;
        for(int i=0;i<rooms[src].size();i++)
        {
            if(visited[rooms[src][i]]==false)
            {
                dfs(rooms[src][i],rooms,visited); 
            }
        }
       
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int i, V=rooms.size();
        vector<bool>visited(V,false);
          dfs(0,rooms,visited);
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                    return false;
            }
        }
        return true;
        
        
        
        
        
    }
};