class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n=image.size();
        int m=image[0].size();
        int oldColor=image[sr][sc];
        dfs(image,sr,sc,oldColor,newColor);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(image[i][j]==-1)
                {
                    image[i][j]=newColor;
                }
            }
        }
        return image;
    }
    void dfs(vector<vector<int>>& image, int sr, int sc, int oldColor,int newColor)
    {
        image[sr][sc]=-1;
        if(sr-1>=0 and image[sr-1][sc]==oldColor)dfs(image,sr-1,sc,oldColor,newColor);
        if(sr+1<image.size() and image[sr+1][sc]==oldColor)dfs(image,sr+1,sc,oldColor,newColor);
        if(sc-1>=0 and image[sr][sc-1]==oldColor)dfs(image,sr,sc-1,oldColor,newColor);
        if(sc+1<image[0].size() and image[sr][sc+1]==oldColor)dfs(image,sr,sc+1,oldColor,newColor);
    }
};