class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i=0;
        int j=nums.size()-1;
       return binarySearch(nums,i,j,target);

    }
    int binarySearch(vector<int>&nums,int i,int j,int target)
    {
        if(i>j)return -1;
        int mid=(i+j)/2;
        if(target==nums[mid])
        {
            return mid;
        }
        if(target>nums[(i+j)/2])
        {
           return binarySearch(nums,mid+1,j,target);
        }
        
           return binarySearch(nums,i,mid-1,target);
        
    }
};