class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mpp;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            int x=nums[i];
            int re=target-x;
          
            if(mpp.find(re)!=mpp.end())
            {
               
                ans.push_back(i);
                ans.push_back(mpp[re]);
                break;
            }
            mpp[nums[i]]=i;
        }
        return ans;
    }
};