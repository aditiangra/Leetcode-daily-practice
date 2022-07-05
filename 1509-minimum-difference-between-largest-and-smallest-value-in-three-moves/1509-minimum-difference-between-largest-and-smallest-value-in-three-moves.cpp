class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        if(n<=3)return 0;
        sort(nums.begin(),nums.end());
        int ans1=nums[n-1]-nums[3];//first 3 elements//
        int ans2=nums[n-2]-nums[2];//first 2 elements//
        int ans3=nums[n-3]-nums[1];//first 1 element//
        int ans4=nums[n-4]-nums[0];//last 4 elements//
        return min(ans1,min(ans2,min(ans3,ans4)));
    }
};