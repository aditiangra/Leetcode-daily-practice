class Solution {
public:
    int f(int ind,int buy,vector<int>&prices, vector<vector<int>> &dp,int fee)
    {
        if(ind>=prices.size())return 0;
        if(dp[ind][buy]!=-1)return dp[ind][buy];
        if(buy)//we need to buy now//we can buy or not buy that particular stock//
        {
            return dp[ind][buy]=max(-prices[ind]+f(ind+1,0,prices,dp,fee),0+f(ind+1,1,prices,dp,fee));
        }
        else//we need to sell now//we can sell or not sell that particular stock//
        {
            return dp[ind][buy]=max(prices[ind]+f(ind+1,1,prices,dp,fee)-fee,0+f(ind+1,0,prices,dp,fee));
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        int ind=0;
        int buy=1;
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f(ind,buy,prices,dp,fee);
    }
};