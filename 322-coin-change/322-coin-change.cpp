class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return f(n-1,amount,coins,dp)>=1e9?-1:f(n-1,amount,coins,dp);
    }
    int f(int ind,int amount,vector<int>&coins, vector<vector<int>> &dp)
    {
        if(ind==0)
        {
            return amount%coins[ind]==0?amount/coins[ind]:1e9;
        }
        if(dp[ind][amount]!=-1)return dp[ind][amount];
        int nontake=f(ind-1,amount,coins,dp);
        int take=INT_MAX;
        if(amount>=coins[ind])
        {
            take=1+f(ind,amount-coins[ind],coins,dp);
        }
        return dp[ind][amount]=min(take,nontake);
    }
};