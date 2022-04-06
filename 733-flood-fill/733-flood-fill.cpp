class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n=image.size();
        int m=image[0].size();
        int color=image[sr][sc];
        if(color!=newColor)
        {
            dfs(image,sr,sc,color,newColor,n,m);
        }
        return image;
    }
    bool isValid(vector<vector<int>>& image, int sr, int sc,int n,int m,int color)
    {
        if(sr>=0 and sr<n and sc>=0 and sc<m and image[sr][sc]==color)return true;
        return false;
    }
    void dfs(vector<vector<int>>& image, int sr, int sc,int color,int newColor,int n,int m)
    {
        image[sr][sc]=newColor;
        if(isValid(image,sr+1,sc,n,m,color)==true)
        {
            dfs(image,sr+1,sc,color,newColor,n,m);
        }
         if(isValid(image,sr-1,sc,n,m,color)==true)
        {
            dfs(image,sr-1,sc,color,newColor,n,m);
        }
         if(isValid(image,sr,sc+1,n,m,color)==true)
        {
            dfs(image,sr,sc+1,color,newColor,n,m);
        }
         if(isValid(image,sr,sc-1,n,m,color)==true)
        {
            dfs(image,sr,sc-1,color,newColor,n,m);
        }
        
    }
    
};