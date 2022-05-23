class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>> adj(n);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
             adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        vector<double>dist(n,0);
        dist[start]=(double)1.0;
        //max heap--->push dis(double),node//
        priority_queue<pair<double,int>>pq;
        pq.push({(double)1.0,start});
        while(pq.empty()==false)
        {
            auto p=pq.top();
            pq.pop();
            double currdist=p.first;
            int currnode=p.second;
            if(currnode==end)return dist[end];
            for(auto it:adj[currnode])
            {
                int nextnode=it.first;
                double prb=it.second;
                if(dist[nextnode]<prb*currdist)
                {
                    dist[nextnode]=prb*currdist;
                    pq.push({dist[nextnode],nextnode});
                }
            }
        }
        return 0;
    }
};