class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<int> nums3(m+n);
        int i=0,j=0,k=0;
        while(i<n and j<m)
        {
            if(nums1[i]<=nums2[j])nums3[k++]=nums1[i++];
            else nums3[k++]=nums2[j++];
        }
        while(i<n)
        {
            nums3[k++]=nums1[i++];
        }
        while(j<m)
        {
            nums3[k++]=nums2[j++];
        }
        int size=n+m;
        for(int i=0;i<size;i++)cout<<nums3[i]<<" ";
        if(size%2==0)
        {
            int a=size/2;
          return double(nums3[a]+nums3[a-1])/2;
        }
        else
        {
            int a=size/2;
            return (double)nums3[a];
        }
    }
};