class Solution {
public:
    bool isValid(vector<vector<int>>& mat,int i,int j)
    {
        if(i>=0 and i<mat.size() and j>=0 and j<mat[0].size() and mat[i][j]==-1)return true;
        return false;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)q.push({i,j});
                else mat[i][j]=-1;
            }
        }
        while(q.empty()==false)
        {
            int s=q.size();
            while(s--)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                if(isValid(mat,x-1,y))
                {
                    q.push({x-1,y});
                    mat[x-1][y]=1+mat[x][y];
                }
                if(isValid(mat,x+1,y))
                {
                    q.push({x+1,y});
                    mat[x+1][y]=1+mat[x][y];
                }
                if(isValid(mat,x,y-1))
                {
                    q.push({x,y-1});
                    mat[x][y-1]=1+mat[x][y];
                }
                if(isValid(mat,x,y+1))
                {
                    q.push({x,y+1});
                    mat[x][y+1]=1+mat[x][y];
                }
            }
        }
        return mat;
    }
};