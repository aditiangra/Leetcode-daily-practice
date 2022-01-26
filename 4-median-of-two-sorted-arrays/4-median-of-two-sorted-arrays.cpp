class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if(m > n)   return findMedianSortedArrays(nums2, nums1);
        
        int low = 0, high = m;
        while(left <= right) {
            int i = low + (high - low) / 2;
            int j = (m + n) / 2 - i;
            
            int left1  = (i == 0)? INT_MIN : nums1[i - 1];
            int right1 = (i == m)? INT_MAX : nums1[i];
            int left2  = (j == 0)? INT_MIN : nums2[j - 1];
            int right2 = (j == n)? INT_MAX : nums2[j];
            
            if(left1 > right2) {
                high = i - 1;	// decrease i
            }
            else if(left2 > right1) {
                low = i + 1;	// increase i
            }
            else {
                if((m + n) & 1)
                    return (i == m)? (double)right2 : (j == n)? (double)right1 : (double)min(right1, right2);
                
                double l = (i == 0)? (double)left2 : (j == 0)? double(left1) : (double)max(left1, left2);
                double r = (i == m)? (double)right2 : (j == n)? (double)right1 : (double)min(right1, right2);
                return (l + r) / 2;
            }
        }
        
        return double(-1);
    }
};