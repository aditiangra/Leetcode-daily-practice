// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int V, vector<int>adj[])
	{
	   vector<bool>visited(V,false);
	   for(int i=0;i<V;i++)
	   {
	       int cnt=0;
	       BFS(i,adj,visited,cnt);
	       if(cnt==V)return i;
	       else return -1;
	   }
	}
	void BFS(int i,vector<int>adj[], vector<bool>visited,int &cnt)
	{
	    visited[i]=true;
	    queue<int>q;
	    q.push(i);
	    while(q.empty()==false)
	    {
	        cnt++;
	        int node=q.front();
	        q.pop();
	        for(auto it:adj[node])
	        {
	            if(visited[it]==false)
	            
	            {
	           visited[it]=true;
	            q.push(it);
	            }
	            
	        }
	    }
	}


};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends