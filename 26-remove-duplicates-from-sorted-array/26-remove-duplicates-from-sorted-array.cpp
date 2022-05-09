class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]==nums[i+1])cnt++;
            else nums[i-cnt+1]=nums[i+1];
        }
        return nums.size()-cnt;
    }
};