class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        while(start<=end)
        {
            if(nums[start]%2==0)
            {
                start++;
            }
            else
            {
                swap(nums[start],nums[end]);
                end--;
            }
        }
        return nums;
    }
};