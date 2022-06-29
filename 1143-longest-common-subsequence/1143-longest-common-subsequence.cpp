class Solution {
public:
    //negative base condition hence we will increase the indexes//
    
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        //ind1-->n
       // ind2--->m
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        //base case//
        for(int ind1=0;ind1<n;ind1++)
        {
            for(int ind2=0;ind2<m;ind2++)
            {
                if(ind1==0 or ind2==0)
                {
                    dp[ind1][ind2]=0;
                }
            }
        }
        for(int ind1=1;ind1<=n;ind1++)
        {
            for(int ind2=1;ind2<=m;ind2++)
            {
                 if(text1[ind1-1]==text2[ind2-1]) dp[ind1][ind2]=1+dp[ind1-1][ind2-1];
                 else dp[ind1][ind2]=max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
            }
        }
        return dp[n][m];
    }
};