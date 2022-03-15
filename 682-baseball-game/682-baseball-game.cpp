class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int>st;
        for(int i=0;i<ops.size();i++)
        {
            if(ops[i]=="C")
            {
                st.pop();
            }
            else if(ops[i]=="D")
            {
                int num=st.top();
                int newnum=2*num;
                st.push(newnum);
            }
            else if(ops[i]=="+")
            {
                int a=st.top();
                st.pop();
                int b=st.top();
                int c=a+b;
                st.push(a);
                st.push(c);
            }
            else
            {
                st.push(stoi(ops[i]));
            }
        }
        int sum=0;
        while(st.empty()==false)
        {
            sum+=st.top();
            st.pop();
        }
        return sum;
    }
};