class Solution {
public:
    string convertToTitle(int n) {
        n--;
        string s="";
        while(n>=0)
        {
            s+=('A'+(n%26));
            n=n/26;
            n--;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};