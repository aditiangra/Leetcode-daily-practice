class Solution {
public:
    int solve(int n)
    {
        int ans=0;
        while(n>0){
        ans+=(n%10)*(n%10);
        n=n/10;}
        return ans;
    }
    bool isHappy(int n) {
        int slow=n,fast=n;
        do
        {
            slow=solve(slow);
            fast=solve(solve(fast));
            if(fast==1)return true;
        }while(slow!=fast);
        return false;
    }
};