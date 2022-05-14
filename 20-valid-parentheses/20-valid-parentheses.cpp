class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(' or s[i]=='{' or s[i]=='[')st.push(s[i]);
            else 
            {
                if(st.empty()==true)return false;
               if(s[i]==')')
               {
                   if(st.empty()==true)return false;
                   if(st.top()=='(')st.pop();
                   else return false;            
               }
                if(s[i]=='}')
                {
                    if(st.empty()==true)return false;
                    if(st.top()=='{')st.pop();
                    else return false;
                }
                if(s[i]==']')
                {
                    if(st.empty()==true)return false;
                    if(st.top()=='[')st.pop();
                    else return false;
                }
                
            }
        }
        if(st.empty()==true)return true;
        else return false;
    }
};