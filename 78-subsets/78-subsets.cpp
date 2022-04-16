class Solution {
public:
    void subset(vector<int>& nums, vector<vector<int>> &ans,vector<int>&res,int ind)
    {
        if(ind==nums.size())
        {
            ans.push_back(res);
            return;
        }
        res.push_back(nums[ind]);
        subset(nums,ans,res,ind+1);
        res.pop_back();
        subset(nums,ans,res,ind+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>res;
        subset(nums,ans,res,0);
        return ans;
    }
};