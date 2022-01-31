// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>visited(V,false);
        vector<int> ans;
        for(int i=0;i<V;i++)
        {
            if(visited[i]==false)
            {
                dfs(i,V,adj,visited,ans);
            }
        }
        return ans;
    }
    void dfs(int i,int V,vector<int> adj[],vector<int>&visited,vector<int>&ans)
    {
        ans.push_back(i);
        visited[i]=true;
        for(auto it:adj[i])
        {
            if(visited[it]==false)
            {
                dfs(it,V,adj,visited,ans);
            }
        }
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends