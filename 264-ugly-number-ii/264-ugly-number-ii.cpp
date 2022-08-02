class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>dp(n);
        dp[0]=1;
        int p2=0;
        int p3=0;
        int p5=0;
        for(int i=1;i<n;i++)
        {
            int multipleof2=dp[p2]*2;
            int multipleof3=dp[p3]*3;
            int multipleof5=dp[p5]*5;
            int mi=min(multipleof2,min(multipleof3,multipleof5));
            dp[i]=mi;
            if(dp[i]==multipleof2)p2++;
            if(dp[i]==multipleof3)p3++;
            if(dp[i]==multipleof5)p5++;
        }
        return dp[n-1];
    }
};