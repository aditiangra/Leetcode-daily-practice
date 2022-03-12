class Solution {
public:
    void dfs(vector<vector<int>>&image,int i,int j,int oldColor,int newColor,int n,int m,vector<vector<int>>&visited)
    {
        if(i<0 or j<0 or i>=n or j>=m)return ;
        if(visited[i][j]==1 or image[i][j]!=oldColor)return ;
        visited[i][j]=1;
        image[i][j]=newColor;
        dfs(image,i-1,j,oldColor,newColor,n,m,visited);
         dfs(image,i+1,j,oldColor,newColor,n,m,visited);
         dfs(image,i,j-1,oldColor,newColor,n,m,visited);
         dfs(image,i,j+1,oldColor,newColor,n,m,visited);
    }
    bool isValid(vector<vector<int>>&image,int i,int j,int oldColor,int newColor,int n,int m,vector<vector<int>>&visited)
    {
        if(i<0 or j<0 or i>=n or j>=m)return false;
        if(visited[i][j]==1 or image[i][j]!=oldColor)return false;
        return true;
    }
    void bfs(vector<vector<int>>&image,int i,int j,int oldColor,int newColor,int n,int m,vector<vector<int>>&visited)
    {
        queue<pair<int,int>>q;
        q.push({i,j});
        visited[i][j]=1;
        while(q.empty()==false)
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                auto it=q.front();
                q.pop();
                int x=it.first;
                int y=it.second;
                if(isValid(image,x-1,y,oldColor,newColor,n,m,visited))
                {visited[x-1][j]=1;
                q.push({x-1,y});}
                  if(isValid(image,x+1,y,oldColor,newColor,n,m,visited))
                  {visited[x+1][y]=1;
                      q.push({x+1,y});}
                  if(isValid(image,x,y-1,oldColor,newColor,n,m,visited))
                  {visited[x][y-1]=1;
                      q.push({x,y-1});}
                  if(isValid(image,x,y+1,oldColor,newColor,n,m,visited))
                  {visited[x][y+1]=1;
                      q.push({x,y+1});}
                
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int x=image.size();
        int y=image[0].size();
        vector<vector<int>> visited(x,vector<int>(y,0));
        int oldColor=image[sr][sc];
        dfs(image,sr,sc,oldColor,newColor,x,y,visited); 
        /*bfs(image,sr,sc,oldColor,newColor,x,y,visited);*/
        return image;
    }
};