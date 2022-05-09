class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int in=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=nums[in-1])
            {
                nums[in++]=nums[i];
            }
        }
        return in;
    }
};