class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            int val=abs(nums[i]);
            int ind=val-1;
            if(nums[ind]<0)
            {
                ans.push_back(val);
            }
            nums[ind]=-nums[ind];
            
        }
        return ans;
    }
};