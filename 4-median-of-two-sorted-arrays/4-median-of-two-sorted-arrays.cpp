class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        for(int i=0;i<nums1.size();i++)
        {
            ans.push_back(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++)
        {
            ans.push_back(nums2[i]);
        }
        sort(ans.begin(),ans.end());
        int n=(ans.size()-1)/2;
       if(ans.size()%2!=0)
       {
           return ans[n];
       }
        else
        {
            return double(ans[n]+ans[n+1])/2;
        }
    }
};