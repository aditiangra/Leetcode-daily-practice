class Solution {
public:
    int superPow(int a, vector<int>& b) {
     int bmod=0;
        for(int val:b)
        {
            bmod=(bmod*10+val)%1140;
        }
        return binaryExp(a,bmod,1337);
    }
    int binaryExp(int a,int b,int m)
    {
        a=a%m;
        int ans=1;
        while(b)
        {
            if(b&1)
            {
                ans=(ans*1LL*a)%m;
            }
            a=(a*a*1LL)%m;
            b>>=1;
        }
        return ans;
    }
};