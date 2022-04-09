class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        vector<long long>nsr(n),nsl(n);
        //NSL
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>=nums[i])
                st.pop();
            nsl[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        //NSR
        stack<int>tt;
        for(int i=n-1;i>=0;i--){
            while(!tt.empty() && nums[tt.top()]>=nums[i])
                tt.pop();
            nsr[i]=tt.empty()?n:tt.top();
            tt.push(i);
        }
        vector<long long>pref(n,0);
        pref[0]=nums[0];
        
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]+nums[i];
        }
        
        for(int i=0;i<n;i++){
            int mn = nums[i];
            int l=nsl[i]+1, r=nsr[i]-1;
            int len, prod;
            if(l<=k && r>=k){
                len = r-l+1;
                prod = mn*len;
                ans = max(ans,prod);
            }
            
        }
        return ans;
    }
};