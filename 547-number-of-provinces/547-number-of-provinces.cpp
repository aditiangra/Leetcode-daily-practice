class Solution {
public:
    int findPar(int node,vector<int>&parent)
    {
        if(node==parent[node])return node;
        return parent[node]=findPar(parent[node],parent);
    }
    void unioni(int i,int j,vector<int>& parent,vector<int>& rank)
    {
        i=findPar(i,parent);
        j=findPar(j,parent);
        if(rank[i]>rank[j])
        {
            parent[j]=i;
        }
        else if(rank[i]<rank[j])
        {
            parent[i]=j;
        }
        else
        {
            parent[i]=j;
            rank[j]++;
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>parent(n);
        vector<int>rank(n,0);
        for(int i=0;i<n;i++)parent[i]=i;        
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(isConnected[i][j]==1)
                {
                    unioni(i,j,parent,rank);
                }
            }
        }
        map<int,int>mpp;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(isConnected[i][j]==1 and mpp.find(findPar(i,parent))==mpp.end())
                {
                    mpp[findPar(i,parent)]=1;
                }
            }
        }
        return mpp.size();
    }
};