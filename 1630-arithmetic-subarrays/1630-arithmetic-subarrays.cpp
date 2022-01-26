class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int i=0;
        int n=nums.size();
        vector<bool>result;
        while(i<l.size())
        {
            vector<int>arr;
            arr=makeTheArray(l[i],r[i],nums);
            result.push_back(checkArithmetic(arr));
            i++;
        }
        return result;
        
    }
    bool checkArithmetic(vector<int> &arr)
    {
        int res=arr[1]-arr[0];

        for(int i=1;i<arr.size();i++)
        {
           int diff=arr[i]-arr[i-1];
            if(diff!=res)return false;
        }
        return true;
    }
    vector<int>makeTheArray(int l,int r,vector<int> nums)
    {
        vector<int>arr;
        for(int i=l;i<=r;i++)
        {
            arr.push_back(nums[i]);
        }
        sort(arr.begin(),arr.end());
        return arr;
    }
};