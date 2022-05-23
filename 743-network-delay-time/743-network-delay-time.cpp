class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dist(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;//distance,node//
        vector<vector<int>> adj[n+1];
        for(int i=0;i<times.size();i++)
        {
            int u=times[i][0];
            int v=times[i][1];
            int w=times[i][2];
            adj[u].push_back({v,w});
        }
        dist[k]=0;
        pq.push({0,k});
        while(pq.empty()==false)
        {
            auto p=pq.top();
            pq.pop();
            int currdist=p.first;
            int currnode=p.second;
            for(auto it:adj[currnode])
            {
                int nextnode=it[0];//v
                int weight=it[1];//w
                if(dist[currnode]+weight<dist[nextnode])
                {
                    dist[nextnode]=currdist+weight;
                    pq.push({dist[nextnode],nextnode});
                }
            }
        }
       for(int i=1;i<n+1;i++)cout<<dist[i]<<" ";
        int res=0;
        for(int i=1;i<n+1;i++)
        {
            res=max(res,dist[i]);
        }
        return res==INT_MAX?-1:res;
    }
};