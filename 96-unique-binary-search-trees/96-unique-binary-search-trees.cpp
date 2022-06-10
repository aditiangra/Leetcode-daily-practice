class Solution {
public:
    int solve(int n,vector<int>&dp)
    {
        
        if(n<=1)return dp[n]=1;
        
        int val=0;
        if(dp[n]!=-1)return dp[n];
        for(int i=0;i<n;i++)
        {
            val+=solve(i,dp)*solve(n-i-1,dp);
        }
        return dp[n]=val;
    }
    int numTrees(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};