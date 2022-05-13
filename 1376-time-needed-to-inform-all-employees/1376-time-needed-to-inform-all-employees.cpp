class Solution {
public:
    int solve(vector<vector<int>> &children, int node, vector<int> &informTime){
        if(children[node].size() == 0)
            return 0;
        int ans = informTime[node];
        int tempmax = 0;
        for(auto el : children[node]){
            tempmax = max(tempmax, solve(children, el, informTime));
        }
        return ans + tempmax;
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> children(n);
        for(int i = 0; i < n; i++){
            if(manager[i] != -1){
                children[manager[i]].push_back(i);
            }
        }
        return solve(children, headID, informTime);
    }
};