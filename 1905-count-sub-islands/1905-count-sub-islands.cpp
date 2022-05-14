class Solution {
public:
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, bool& res) {
        if(i < 0 || i >= grid2.size() || j < 0 || j >= grid2[0].size() || grid2[i][j] != 1 )
            return;
        if(grid2[i][j]!=grid1[i][j]) {
            cout << i << " " << j << endl;
            res = false;
            return;
        }
        grid2[i][j] = -1;
        dfs(grid1, grid2, i-1, j, res);
        dfs(grid1, grid2, i+1, j, res);
        dfs(grid1, grid2, i, j-1, res);
        dfs(grid1, grid2, i, j+1, res);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid2.size();
        int m = grid2[0].size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid2[i][j] == 1) {
                    bool res = true;
                    dfs(grid1, grid2, i, j, res);
                    if(res) {
                        // cout << i << " " << j << endl;
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};