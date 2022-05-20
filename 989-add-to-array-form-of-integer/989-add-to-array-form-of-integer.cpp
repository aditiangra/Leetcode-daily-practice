class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans;
        int i=num.size()-1;
        int carry=0;
        while(i>=0 or k!=0)
        {
            int sum=carry;
            if(i>=0)sum+=num[i--];
            if(k!=0)
            {
                sum+=(k%10);
                k=k/10;
            }
            carry=sum/10;
            ans.push_back(sum%10);
        }
        if(carry!=0)
        {
            ans.push_back(carry);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};