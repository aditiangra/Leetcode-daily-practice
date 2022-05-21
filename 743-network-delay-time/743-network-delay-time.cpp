class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});//distance,source//
        vector<int>dist(n+1,INT_MAX);
        dist[k]=0;
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto i:times)
        {
            adj[i[0]].push_back({i[1],i[2]});
        }
        while(pq.empty()==false)
        {
            auto p=pq.top();
            pq.pop();
            int distance=p.first;
            int node=p.second;
            for(auto it:adj[node])
            {
                int v=it.first;
                int wt=it.second;
                if(dist[v]>wt+distance)
                {
                    dist[v]=wt+distance;
                    pq.push({dist[v],v});
                }
            }
        }
        int res=0;
        for(int i=1;i<=n;i++)
        {
            res=max(res,dist[i]);
        }
        return res==INT_MAX?-1:res;
    }
};