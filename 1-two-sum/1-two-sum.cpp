class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>arr=nums;
        sort(arr.begin(),arr.end());
        int i=0,j=nums.size()-1;
        int n1,n2;
        while(i<j)
        {
            if(arr[i]+arr[j]==target)
            {
                n1=arr[i];
                n2=arr[j];
                break;
            }
            else if(arr[i]+arr[j]>target)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            if(n1==nums[i])
            {
                ans.push_back(i);
            }
            else if(n2==nums[i])
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};