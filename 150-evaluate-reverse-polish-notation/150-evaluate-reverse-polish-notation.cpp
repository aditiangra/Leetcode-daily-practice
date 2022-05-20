class Solution {
public:
    int evalRPN(vector<string>& t) {
        stack<int> st;
        for(int i=0;i<t.size();i++)
        {
            if(t[i]=="+" or t[i]=="-" or t[i]=="*" or t[i]=="/")
            {
                int x=st.top();
                st.pop();
                int y=st.top();
                st.pop();
                switch(t[i][0])
                {
                    case '+':st.push(y+x);
                        break;
                    case '-': st.push(y-x);
                        break;
                    case '*':st.push(y*x);
                        break;
                    case '/':st.push(y/x);
                        break;
                }
            }
            else
            {
                st.push(stoi(t[i]));
            }
        }
        return st.top();
    }
};