class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n=image.size();
        int m=image[0].size();
        int color=image[sr][sc];
        if(color!=newColor)
        {
            bfs(image,sr,sc,color,newColor,n,m);
        }
        return image;
    }
    bool isValid(vector<vector<int>>& image, int sr, int sc,int color,int n,int m)
    {
        if(sr>=0 and sr<n and sc>=0 and sc<m and image[sr][sc]==color)return true;
        return false;
    }
    void bfs(vector<vector<int>>& image, int sr, int sc,int color,int newColor,int n,int m)
    {
       queue<pair<int,int>>q;
        q.push({sr,sc});
        image[sr][sc]=newColor;
        while(q.empty()==false)
        {
            auto pair=q.front();
            q.pop();
            int x=pair.first;
            int y=pair.second;
            if(isValid(image,x-1,y,color,n,m)==true)
            {
                image[x-1][y]=newColor;
                q.push({x-1,y});
            }
             if(isValid(image,x+1,y,color,n,m)==true)
            {
                 image[x+1][y]=newColor;
                q.push({x+1,y});
            }
             if(isValid(image,x,y-1,color,n,m)==true)
            {
                 image[x][y-1]=newColor;
                q.push({x,y-1});
            }
             if(isValid(image,x,y+1,color,n,m)==true)
            {
                 image[x][y+1]=newColor;
                q.push({x,y+1});
            }
        }
        
    }
    
};