class Solution {
public:
    int rob(vector<int>& nums) {
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
};