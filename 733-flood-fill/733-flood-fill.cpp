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
    void bfs(vector<vector<int>>& image,int i, int j,int color, int newColor,int n,int m)
    {
        queue<pair<int,int>>q;
        q.push({i,j});
        while(q.empty()==false)
        {
            auto current=q.front();
            q.pop();
            int x=current.first;
            int y=current.second;
            image[x][y]=newColor;
            if(isValid(image,x+1,y,color,newColor,n,m))
        {
            q.push({x+1,y});
        }
         if(isValid(image,x-1,y,color,newColor,n,m))
        {
            q.push({x-1,y});
        }
         if(isValid(image,x,y+1,color,newColor,n,m))
        {
          q.push({x,y+1});
        }
         if(isValid(image,x,y-1,color,newColor,n,m))
        {
            q.push({x,y-1});
        }
        }
        
    }
    void dfs(vector<vector<int>>& image,int i, int j,int color, int newColor,int n,int m)
    {
        image[i][j]=newColor;
        if(isValid(image,i+1,j,color,newColor,n,m))
        {
            dfs(image,i+1,j,color,newColor,n,m);
        }
         if(isValid(image,i-1,j,color,newColor,n,m))
        {
            dfs(image,i-1,j,color,newColor,n,m);
        }
         if(isValid(image,i,j+1,color,newColor,n,m))
        {
            dfs(image,i,j+1,color,newColor,n,m);
        }
         if(isValid(image,i,j-1,color,newColor,n,m))
        {
            dfs(image,i,j-1,color,newColor,n,m);
        }
    }
    bool isValid(vector<vector<int>>& image,int i, int j,int color, int newColor,int n,int m)
    {
        if(i>=0 and j>=0 and i<n and j<m and image[i][j]==color)return true;
        return false;
    }
};