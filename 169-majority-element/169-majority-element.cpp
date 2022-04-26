class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int fl=floor(n/2);
        map<int,int>mpp;
        for(int i=0;i<n;i++)
        {
            mpp[nums[i]]++;
        }
        for(auto it:mpp)
        {
            if(it.second>fl)
            {
                return it.first;
            }
        }
        return 1;
    }
};