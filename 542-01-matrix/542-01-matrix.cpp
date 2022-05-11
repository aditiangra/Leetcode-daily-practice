class Solution {
public:
    bool isValid(vector<vector<int>>& grid,int i,int j)
    {
        if(i>=0 and j>=0 and i<grid.size() and j<grid[0].size() and grid[i][j]==1)return true;
        return false;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>>ans=mat;
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({i,j});
                    ans[i][j]=0;
                }
            }
        }
        int cnt=0;
        while(q.empty()==false)
        {
            cnt++;
            int n=q.size();
            for(int k=0;k<n;k++)
            {
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                if(isValid(mat,i-1,j))
                {
                    q.push({i-1,j});
                    mat[i-1][j]=0;
                    ans[i-1][j]=cnt;
                }
                if(isValid(mat,i+1,j))
                {
                    q.push({i+1,j});
                    mat[i+1][j]=0;
                    ans[i+1][j]=cnt;
                }
                if(isValid(mat,i,j-1))
                {
                    q.push({i,j-1});
                    mat[i][j-1]=0;
                    ans[i][j-1]=cnt;
                }
                if(isValid(mat,i,j+1))
                {
                    q.push({i,j+1});
                    mat[i][j+1]=0;
                    ans[i][j+1]=cnt;
                }
            }
            
        }
        return ans;
    }
};