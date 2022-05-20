class Solution {
public:
    vector<int>parent;
    int findPar(int node)
    {
        if(node==parent[node])return node;
        return parent[node]=findPar(parent[node]);
    }
    bool join(int x,int y)
    {
        x=findPar(x);
        y=findPar(y);
        if(x==y)return false;
        parent[y]=x;
        return true;
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        parent.resize(n);
        for(int i=0;i<n;i++)parent[i]=i;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(stones[i][0]==stones[j][0] or stones[i][1]==stones[j][1])
                {
                   if(join(i,j)==true)cnt++;
                }
            }
        }
        return cnt;
    }
};