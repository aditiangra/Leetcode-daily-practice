class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
      vector<bool>visited(rooms.size(),false);
        queue<int>q;
        q.push(0);
        visited[0]=true;
        while(q.empty()==false)
        {
            int top=q.front();
            q.pop();
            for(int i=0;i<rooms[top].size();i++)
            {
                if(visited[rooms[top][i]]==false)
                {
                    q.push(rooms[top][i]);
                    visited[rooms[top][i]]=true;
                }
            }
        }
        for(int i=0;i<visited.size();i++)
        {
            if(visited[i]==false)return false;
        }
        return true;
    }
};