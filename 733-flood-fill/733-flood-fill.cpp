class Solution {
public:
   bool isValid(vector<vector<int> > & arr,int i,int j,int el){
        if(i<0 or j<0 or i>=arr.size() or j>=arr[0].size() or el!=arr[i][j])return false;
       return true;
    }
    
    
    
    void bfs(int sr,int sc,int k,int ele,vector< vector<int> > & arr){
        queue<pair<int,int> > q;
        q.push(make_pair(sr,sc));
        while( q.empty()==false){
            auto current=q.front();
            q.pop();
            int i=current.first,j=current.second;
            arr[i][j]=k;
            if(isValid(arr,i-1,j,ele)) q.push(make_pair(i-1,j));
            if(isValid(arr,i,j-1,ele)) q.push(make_pair(i,j-1));
            if(isValid(arr,i+1,j,ele)) q.push(make_pair(i+1,j));
            if(isValid(arr,i,j+1,ele)) q.push(make_pair(i,j+1));
        }
    }

    


    void dfs(int i,int j,int k,int ele,vector< vector<int> > & arr){
        if(i<0 or j<0 or i>=arr.size() or j>=arr[0].size() or arr[i][j]!=ele) return;
        arr[i][j]=k;
        dfs(i-1,j,k,ele,arr);
        dfs(i,j-1,k,ele,arr);
        dfs(i+1,j,k,ele,arr);
        dfs(i,j+1,k,ele,arr);
    }
    vector<vector<int> > floodFill(vector<vector<int> >& image, int sr, int sc, int newColor) {
        int k=newColor;
        int ele=image[sr][sc];
        if (ele != newColor)
            // dfs(sr,sc,newColor,image[sr][sc],image);
            bfs(sr,sc,k,ele,image);
        return image;
    }


};