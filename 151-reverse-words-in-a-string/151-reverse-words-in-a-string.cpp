class Solution {
public:
    string reverseWords(string s) {
        if(s.size()==0)return s;
        stack<string>st;
        for(int i=0;i<s.size();i++)
        {
            string temp="";
            if(s[i]==' ')continue;
            while(i<s.size() and s[i]!=' ')
            {
                temp+=s[i];
                i++;
            }
            st.push(temp);
        }
        string result="";
        while(!st.empty()) {
            result += st.top(); st.pop();
            if(!st.empty()) result += " ";
        }
    
        return result;
    }
};