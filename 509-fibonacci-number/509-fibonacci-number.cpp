class Solution {
public:
    int fib(int n) {
       vector<int>dp(n+1,-1);
        int ans=calculate(n,dp);
        return ans;
    }
    int calculate(int n,vector<int>& dp)
    {
        if(n==0 or n==1)
        {
            dp[n]=n;
        }
        if(dp[n]!=-1)return dp[n];
        return dp[n]=calculate(n-1,dp)+calculate(n-2,dp);
    }
};