class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        firstoccurence(nums,target,ans);
        lastoccurence(nums,target,ans);
        return ans;
    }
    void firstoccurence(vector<int>&nums,int target,vector<int>&ans)
    {
        int start=0;
        int end=nums.size()-1;
        int res=-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(target==nums[mid])
            {
                res=mid;
                end=mid-1;
            }
            else if(target>nums[mid])
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
            
        }
        ans.push_back(res);
    }
    void lastoccurence(vector<int>&nums,int target,vector<int>&ans)
    {
        int start=0;
        int end=nums.size()-1;
        int res=-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(target==nums[mid])
            {
                res=mid;
                start=mid+1;
            }
            else if(target>nums[mid])
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
            
        }
        ans.push_back(res);
    }
};