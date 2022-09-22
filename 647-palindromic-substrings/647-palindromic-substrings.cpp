class Solution {
public:
    int countSubstrings(string s) {
         int n = s.length();
        int cnt = 0, i, j, k;
        vector<vector<int>>dp(n, vector<int>(n, 0));
        for(i = 0; i < n; i++) {
            dp[i][i] = 1;
            cnt++;
        }
        for(i = 1; i < n; i++){
            if(s[i] == s[i - 1])
                dp[i-1][i] = 1, cnt++;
        }
        for(i = 3; i <= n; i++) {
            for(j = 0; j <= n - i; j++) {
                int k = j + i - 1;
                if(s[j] == s[k] && dp[j+1][k-1])
                    dp[j][k] = 1, cnt++;
            }
        }
        return cnt;   
    }
};