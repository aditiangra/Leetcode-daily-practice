class Solution {
public:
    bool isValid(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == -1 || grid[i][j] == -2)
            return false;
        return true;
    }
    void dfs(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != 1)
            return;
        grid[i][j] = 2;
        dfs(grid, i-1, j);
        dfs(grid, i+1, j);
        dfs(grid, i, j-1);
        dfs(grid, i, j+1);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; i++) {
            int flag = 0;
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    dfs(grid, i, j);
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)
                break;
        }
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++)
                if(grid[i][j] == 2) {
                    q.push({i, j});
                    grid[i][j] = -1;
                }
        }
        int ans = 0;
        while(!q.empty()) {
            ans++;
            int s = q.size();
            cout << s << endl;
            while(s--) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                if(grid[i][j] == -2 || grid[i][j] == 1)
                    return ans-2;
                if(isValid(grid, i-1, j)) {
                    q.push({i-1, j});
                    if(grid[i-1][j] != 1)
                        grid[i-1][j] = -1;
                    else
                        grid[i-1][j] = -2;
                }
                if(isValid(grid, i+1, j)) {
                    q.push({i+1, j});
                    if(grid[i+1][j] != 1)
                        grid[i+1][j] = -1;
                    else
                        grid[i+1][j] = -2;
                }
                if(isValid(grid, i, j-1)) {
                    q.push({i, j-1});
                    if(grid[i][j-1] != 1)
                        grid[i][j-1] = -1;
                    else
                        grid[i][j-1] = -2;
                }
                if(isValid(grid, i, j+1)) {
                    q.push({i, j+1});
                    if(grid[i][j+1] != 1)
                        grid[i][j+1] = -1;
                    else
                        grid[i][j+1] = -2;
                }
            }
        }
        return -1;
    }
};