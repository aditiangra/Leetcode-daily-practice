class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
       int curri=0;
        int prev1=0,prev2=0;
        for(int i=2;i<=n;i++)
        {
          curri=min(prev1+cost[i-1],prev2+cost[i-2]);
            prev2=prev1;
            prev1=curri;
        }
        return prev1;
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