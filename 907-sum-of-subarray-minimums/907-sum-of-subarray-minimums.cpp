class Solution {
public:
    vector<int> NSR(vector<int>&arr,int n)
    {
        vector<int>nsr(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--)
        {
            while(st.empty()==false and arr[st.top()]>arr[i])st.pop();
            if(i<n)
            {
                if(st.empty()==false)
                {
                    nsr[i]=st.top();
                }
                else
                {
                    nsr[i]=n;
                }
            }
            st.push(i);
        }
        return nsr;
    }
    vector<int> NSL(vector<int>&arr,int n)
    {
        vector<int>nsl(n);
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            while(st.empty()==false and arr[st.top()]>=arr[i])st.pop();
            if(i<n)
            {
                if(st.empty()==false)
                {
                    nsl[i]=st.top();
                }
                else
                {
                    nsl[i]=-1;
                }
            }
            st.push(i);
        }
        return nsl;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> nsr=NSR(arr,n);
        vector<int>nsl=NSL(arr,n);
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            long long l=nsr[i]-i;
            long long r=i-nsl[i];
            ans+=(l*r*arr[i]);
            ans=ans%1000000007;
        }
        return ans;
        
        }
};