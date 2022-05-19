class Solution {
public:
    string solve(string s)
    {
        stack<char>st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='#')
            {if(st.empty()==false)st.pop();}
            else st.push(s[i]);
        }
        string ans="";
        while(st.empty()==false)
        {
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
    bool backspaceCompare(string s, string t) {
        string ans1="";
         string ans2="";
        ans1=solve(s);
        ans2=solve(t);
        if(ans1==ans2)return true;
        return false;
        
    }
};