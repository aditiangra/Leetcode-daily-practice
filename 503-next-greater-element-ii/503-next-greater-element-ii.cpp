class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n=arr.size();
        vector<int>nge(n);
        stack<int>st;
        for(int i=2*n-1;i>=0;i--)
        {
            while(st.empty()==false and st.top()<=arr[i%n])st.pop();
            if(i<n)
            {
                nge[i%n]=st.empty()==false?st.top():-1;
            }
            st.push(arr[i%n]);
        }
        return nge;
    }
};