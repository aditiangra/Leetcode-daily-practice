class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>& image,vector<vector<int>>& ans,int newColor,int iniColor,int delRow[],int delCol[])
    {
        ans[row][col]=newColor;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++)
        {
            int nrow=row+delRow[i];
            int ncol=col+delCol[i];
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && image[nrow][ncol]==iniColor && ans[nrow][ncol]!=newColor)
            {
                dfs(nrow,ncol,image,ans,newColor,iniColor,delRow,delCol);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor=image[sr][sc];
        vector<vector<int>> ans=image;
        int delRow[]={-1,0,1,0};
        int delCol[]={0,-1,0,1};
        dfs(sr,sc,image,ans,color,iniColor,delRow,delCol);
        return ans;
    }
};