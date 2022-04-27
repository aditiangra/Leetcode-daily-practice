class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    for(int a=k+1;a<n;a++)
                    {
                        if(nums[i]+nums[j]+nums[k]==nums[a])
                        {
                            cnt++;
                        }
                    }
                }
            }
        }
        return cnt;
    }
};