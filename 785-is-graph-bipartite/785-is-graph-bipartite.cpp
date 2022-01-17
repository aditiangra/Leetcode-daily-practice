class Solution {
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int V=adj.size();
         vector<int>color(V,-1);
	    for(int i=0;i<V;i++)
	    {
	        if(color[i]==-1)
	        {
                color[i]=1;
	            if(check(adj,color,i)==false)return false;
	        }
	    }
	    return true;
    }
    	bool check( vector<vector<int>>& adj, vector<int>&color,int src)
	{
	  
	    for(auto it:adj[src])
	    {
	        if(color[it]==-1)
	        {
	            color[it]=1-color[src];
                if(check(adj,color,it)==false)return false;
	        }
	        else if(color[it]==color[src])return false;
	  
	      
	    }
              return true;
	}
};