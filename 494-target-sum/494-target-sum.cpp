class Solution {
public:
    int cnt=0;
    void solve(vector<int>& nums, int target,int ind,int sum)
    {
        if(ind==nums.size() and target==sum)
        {
            cnt++;
            return ;
        }
        if(ind<nums.size()){
        solve(nums,target,ind+1,sum+nums[ind]);
        solve(nums,target,ind+1,sum-nums[ind]);}
    }
    int findTargetSumWays(vector<int>& nums, int target) {
       solve(nums,target,0,0);
        return cnt;
        
    }
};