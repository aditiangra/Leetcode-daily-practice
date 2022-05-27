class Solution {
public:
    int climbStairs(int n) {
     vector<int>dp(n+1,-1);
    int ans=solve(dp,n);
        return ans;
    }
    int solve(vector<int>& dp,int n)
    {
       if(n==0 or n==1)return n;
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};