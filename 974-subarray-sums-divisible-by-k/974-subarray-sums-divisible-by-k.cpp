class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        int count=0;
        int cumsum=0;
        mpp[0]++;
        for(int i=0;i<nums.size();i++)
        {
            cumsum+=nums[i];
            int re=cumsum%k;
            if(re<0)
            {
                re+=k;
            }
            if(mpp.count(re)>0)
            {
                count+=mpp[re];
            }
            mpp[re]++;
        }
        return count;
    }
};