class Solution {
public:
    int climbStairs(int n) {
     vector<int>dp(n+1,-1);
    int ans=solve(dp,n);
        return ans;
    }
    int solve(vector<int>& dp,int n)
    {
        int prev1=1,prev2=1,curri;
        
        dp[0]=1;
        dp[1]=1;
      for(int i=2;i<=n;i++)
      {
          curri=prev1+prev2;
           prev2=prev1;
          prev1=curri;
         
      }
        return prev1;
    }
};