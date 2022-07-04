class Solution {
public:
  
    int maxProfit(vector<int>& prices) {
        int ind=0;
        int buy=1;
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        //base condition//
        dp[n][0]=0;
        dp[n][1]=0;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=1;j>=0;j--)
            {
                 if(j)//we need to buy now//we can buy or not buy that particular stock//
        {
             dp[i][j]=max(-prices[i]+dp[i+1][0],0+dp[i+1][1]);
        }
        else//we need to sell now//we can sell or not sell that particular stock//
        {
             dp[i][j]=max(prices[i]+dp[i+1][1],0+dp[i+1][0]);
        }
            }
        }
        return dp[0][1];
    }
};