class Solution {
public:
    int findPar(int node,vector<int>& parent)
    {
        if(node==parent[node])return node;
        else return parent[node]=findPar(parent[node],parent);
    }
    void unioni(int i,int j,vector<int>& parent,vector<int>& rank)
    {
        i=findPar(i,parent);
        j=findPar(j,parent);
        if(i!=j)
        {
            if(rank[i]>rank[j])
            {
                parent[j]=i;
            }
            else if(rank[i]<rank[j])
            {
                parent[j]=i;
            }
            else
            {
                parent[i]=j;
                rank[j]++;
            }
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>parent(1001);
        vector<int>rank(1001,0);
        int n=edges.size();
        vector<int>answer;
        for(int i=0;i<1001;i++)parent[i]=i;
        for(int i=0;i<n;i++)
        {
            if(findPar(edges[i][0],parent)==findPar(edges[i][1],parent))
            {
                answer.push_back(edges[i][0]);
                answer.push_back(edges[i][1]);
                return answer;
            }
            else
            {
                unioni(edges[i][0],edges[i][1],parent,rank);
            }
            
        }
        return answer;
    }
};