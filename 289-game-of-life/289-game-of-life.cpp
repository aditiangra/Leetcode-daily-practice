class Solution {
public:
    int liveCount(vector<vector<int>>& board, int i, int j) {
        int n = board.size();
        int m = board[0].size();
        int ans = 0;
        ans += i-1 >= 0 && board[i-1][j] == 1 ? 1 : 0;
        ans += j-1 >= 0 && board[i][j-1] == 1 ? 1 : 0;
        ans += i-1 >= 0 && j-1 >= 0 && board[i-1][j-1] == 1 ? 1 : 0;
        ans += i+1 < n && board[i+1][j] == 1 ? 1: 0;
        ans += j+1 < m && board[i][j+1] == 1 ? 1 : 0;
        ans += i+1 < n && j+1 < m && board[i+1][j+1] == 1 ? 1 : 0;
        ans += i+1 < n && j-1 >= 0 && board[i+1][j-1] == 1 ? 1 : 0;
        ans += i-1>= 0 && j+1 < m && board[i-1][j+1] == 1 ? 1 : 0;
        return ans;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> temp = board;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int l = liveCount(temp, i, j);
                if(board[i][j] == 1) {
                    if(l < 2 || l > 3)
                        board[i][j] = 0;
                }
                else {
                    board[i][j] = l == 3 ? 1 : 0;
                }
            }
        }
    }
};