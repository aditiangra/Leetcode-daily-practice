class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        return solve(n,cost,dp);
    }
    int solve(int n,vector<int>&cost,vector<int>&dp)
    {
        if(n==0)return 0;
        if(n==1)return 0;
        if(n<=1)dp[n]=0;
        if(dp[n]!=-1)return dp[n];
        int fc=solve(n-1,cost,dp)+cost[n-1];
        int sc=solve(n-2,cost,dp)+cost[n-2];
        return dp[n]=min(fc,sc);
    }
};