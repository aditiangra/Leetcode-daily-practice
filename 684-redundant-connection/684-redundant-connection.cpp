class Solution {
public:
    int findPar(int node,vector<int>&parent)
    {
        if(node==parent[node])return node;
        return parent[node]=findPar(parent[node],parent);
    }
    void unioni(int i,int j,vector<int>&parent)
    {
        i=findPar(i,parent);
        j=findPar(j,parent);
        if(i==j)return;
        else {parent[i]=j;
        return;}
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>parent(1001);
       
        for(int i=0;i<1001;i++)
        {
            parent[i]=i;
        }
        vector<int> answer;
        for(int i=0;i<edges.size();i++)
        {
            if(findPar(edges[i][0],parent)==findPar(edges[i][1],parent))
            {
                answer.push_back(edges[i][0]);
                answer.push_back(edges[i][1]);
                return answer;
            }
            else
            {
                unioni(edges[i][0],edges[i][1],parent);
            }
        }
        return answer;
    }
};