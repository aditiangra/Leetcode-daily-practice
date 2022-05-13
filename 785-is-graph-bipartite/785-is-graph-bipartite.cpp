class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int>color(V,-1);
        for(int i=0;i<V;i++)
        {
            if(color[i]==-1)
            {
                color[i]=1;
                if(check(graph,color,i)==false)return false;
            }
        }
        return true;
    }
    bool check(vector<vector<int>>& graph,vector<int>&color,int node)
    {
        for(auto it:graph[node])
        {
            if(color[it]==-1)
            {
                color[it]=1-color[node];
                if(check(graph,color,it)==false)return false;
            }
            else if(color[it]==color[node])return false;
        }
        return true;
    }
};