class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> in_degree(n,0),ans;
        
          for(auto edge:edges){
              in_degree[edge[1]]++;
          }
          for(int i=0;i<n;i++){
              if(in_degree[i] == 0)ans.push_back(i);
          }
        return ans;
    }
};