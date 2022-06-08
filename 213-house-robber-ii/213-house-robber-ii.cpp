class Solution {
public:
    int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    int prev1=nums[0];
 int prev2=0;
 int curri;
 for(int i=1;i<n;i++)
 {
     int pick=nums[i];
     if(i>=2)pick+=prev2;
     int nonpick=0+prev1;
     curri=max(pick,nonpick);
     prev2=prev1;
     prev1=curri;
 }
 return prev1;
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp1,temp2;
        if(n==1)return nums[0];
        for(int i=0;i<n;i++)
        {
            if(i!=0)
            {
                temp1.push_back(nums[i]);
            }
            if(i!=n-1)
            {
                temp2.push_back(nums[i]);
            }
        }
        int ans1= maximumNonAdjacentSum(temp1);
        int ans2= maximumNonAdjacentSum(temp2);
        return max(ans1,ans2);
    }
};