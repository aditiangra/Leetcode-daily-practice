class Solution {
public:
    int f(int ind,int buy,int cap,vector<int>& prices, vector<vector<vector<int>>> &dp)
    {
        //base conditions//
        if(ind==prices.size())return 0;
        if(cap==0)return 0;
        if(dp[ind][buy][cap]!=-1)return dp[ind][buy][cap];
        if(buy)//either buy or not buy//
        {
            return dp[ind][buy][cap]=max(-prices[ind]+f(ind+1,0,cap,prices,dp),0+f(ind+1,1,cap,prices,dp));
        }
        else
        {
           return dp[ind][buy][cap]=max(prices[ind]+f(ind+1,1,cap-1,prices,dp),0+f(ind+1,0,cap,prices,dp)); 
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int buy=1;
        int cap=2;
        //n*2*3//ind,buy,cap//
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(0,buy,cap,prices,dp);
    }
};