class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool>visited(rooms.size(),0);
        queue<int>q;
        q.push(0);
        visited[0]=true;
        while(q.empty()==false)
        {
            int size=q.size();
            while(size--)
            {
                int x=q.front();
                q.pop();
                for(auto it:rooms[x])
                {
                    if(visited[it]==false){
                    q.push({it});
                    visited[it]=true;
                    }
                }
            }
        }
        for(int i=0;i<rooms.size();i++)
        {
            if(visited[i]==false)return false;
        }
        return true;
    }
};