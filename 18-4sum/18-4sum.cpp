class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        int n=nums.size();
        if(n==0)return res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            int target3=target-nums[i];
            for(int j=i+1;j<n;j++)
            {
                int target2=target3-nums[j];
                int front=j+1;
                int back=n-1;
                while(front<back)
                {
                    int two_sum=nums[front]+nums[back];
                    if(target2>two_sum)
                    {
                        front++;
                    }
                    else if(target2<two_sum)
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
                        res.push_back(quad);
                        while(front<back and nums[front]==quad[2])++front;
                        while(front<back and nums[back]==quad[3])--back;
                    }
                }
                while(j+1<n and nums[j]==nums[j+1])++j;
            }
            while(i+1<n and nums[i]==nums[i+1])++i;
        }
        return res;
    }
};