class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>result;
        if(nums.empty()==true)return result;
        int n=nums.size();
        int target3,target2,front,back,two_sum;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            target3=target-nums[i];
            for(int j=i+1;j<n;j++)
            {
                target2=target3-nums[j];
                front=j+1;
                back=n-1;
                while(front<back)
                {
                    two_sum=nums[front]+nums[back];
                    if(two_sum<target2)
                    {
                     front++;   
                    }
                    else if(two_sum>target2)
                    {
                        back--;
                    }
                    else
                    {
                        vector<int>quad(4,0);
                        quad[0]=nums[i];
                        quad[1]=nums[j];
                        quad[2]=nums[front];
                        quad[3]=nums[back];
                        result.push_back(quad);
                          while(front<back and nums[front]==quad[2])++front;
                        while(front<back and nums[back]==quad[3])--back;
                    }
                }
                while(j+1<n and nums[j]==nums[j+1])++j;
            }
            while(i+1<n and nums[i]==nums[i+1])++i;
        }
        return result;
    }
};