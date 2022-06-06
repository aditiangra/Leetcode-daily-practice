class Solution {
public:
    bool isValid(vector<vector<int>>& image,int i,int j,int oldColor,int newColor)
    {
        if(i>=0 and j>=0 and i<image.size() and j<image[0].size() and image[i][j]==oldColor)return true;
        return false;
    }
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
    void dfs(vector<vector<int>>& image,int i,int j,int oldColor,int newColor)
    {
        image[i][j]=-1;
        if(isValid(image,i-1,j,oldColor,newColor))
        {
            dfs(image,i-1,j,oldColor,newColor);
        }
        if(isValid(image,i+1,j,oldColor,newColor))
        {
            dfs(image,i+1,j,oldColor,newColor);
        }
        if(isValid(image,i,j-1,oldColor,newColor))
        {
            dfs(image,i,j-1,oldColor,newColor);
        }
        if(isValid(image,i,j+1,oldColor,newColor))
        {
            dfs(image,i,j+1,oldColor,newColor);
        }
    }
};