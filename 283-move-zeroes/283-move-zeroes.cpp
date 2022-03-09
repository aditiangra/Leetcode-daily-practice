class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cnt=0;
        vector<int>arr;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
            {
                arr.push_back(nums[i]);
            }
            else
            {
                cnt++;
            }
        }
        while(cnt--)
        {
            arr.push_back(0);
        }
        for(int i=0;i<nums.size();i++)
        {
            nums[i]=arr[i];
        }
    }
};