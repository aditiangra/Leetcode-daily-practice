class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums2, vector<int>& nums1) {
        map<int,int>mpp;
        stack<int>st;
        for(int i=nums1.size()-1;i>=0;i--)
        {
            while(st.empty()==false and st.top()<=nums1[i])st.pop();
            if(i<nums1.size())
            {
                if(st.empty()==false)mpp[nums1[i]]=st.top();
                else mpp[nums1[i]]=-1;
            }
            st.push(nums1[i]);
        }
        vector<int>result;
        for(int i=0;i<nums2.size();i++)
        {
            result.push_back(mpp[nums2[i]]);
        }
        return result;
    }
};