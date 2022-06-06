class Solution {
public:
    int climbStairs(int n) {
       vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
    int solve(int n,vector<int>&dp)
    {
         if(n==0)return 1;
        if(n==0)dp[n]=1;
        if(dp[n]!=-1)return dp[n];
        int left=solve(n-1,dp);
        int right=0;
     if(n>=2)  right=solve(n-2,dp);
        return dp[n]=left+right;
    }
};