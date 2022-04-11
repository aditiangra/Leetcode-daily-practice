class Solution {
public:
    void rever(vector<char>& s,int i,int n)
    {
        if(i>=n/2)
        {
            return ;
        }
        swap(s[i],s[n-1-i]);
        rever(s,i+1,n);
    }
    void reverseString(vector<char>& s) {
        int n=s.size();
        int i=0;
        rever(s,i,n);
    }
};