class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
       dp[0]=0;
        dp[1]=0;
        for(int i=2;i<=n;i++)
        {
            dp[i]=min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
        }
        return dp[n];
    }
    /*int solve(int n,vector<int>&cost,vector<int>&dp)
    {
        if(n==0)return 0;
        if(n==1)return 0;
        if(n<=1)dp[n]=0;
        if(dp[n]!=-1)return dp[n];
        int fc=solve(n-1,cost,dp)+cost[n-1];
        int sc=solve(n-2,cost,dp)+cost[n-2];
        return dp[n]=min(fc,sc);
    }*/
};