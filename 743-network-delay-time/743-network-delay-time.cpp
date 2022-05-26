class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int V, int K) {
        int E=times.size();
        if(E==0)return 0;
        vector<int>dist(V+1,INT_MAX);
        dist[K]=0;
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<E;j++)
            {
                int u=times[j][0];
                int v=times[j][1];
                int wt=times[j][2];
                if(dist[u]!=INT_MAX && dist[u]+wt<dist[v])
                {
                    dist[v]=dist[u]+wt;
                }
            }
        }
        int res=0;
        for(int i=1;i<=V;i++)
        {
            res=max(res,dist[i]);
        }
        return res==INT_MAX?-1:res;
        
    }
};