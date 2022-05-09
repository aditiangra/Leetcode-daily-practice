class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> arr(nums.size()+1);
        for(auto it:nums)
        {
            arr[it]++;
        }
        for(int i=1;i<=nums.size();i++)
        {
            if(arr[i]>1)
            {
                return i;
            }
        }
        return 0;
    }
};