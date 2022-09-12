class Solution {
public:
    string reverseWords(string s) {
         string ans="",temp="";
        vector<string>v;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]!=' ')
             temp+=s[i];
            else
            { 
                   if(temp!="")
                   {
                        reverse(temp.begin(),temp.end());
                        v.push_back(temp);
                        temp="";
                   }
            }
        }
        reverse(temp.begin(),temp.end());
        if(temp!="")
         v.push_back(temp);
        for(int i=0;i<v.size();i++)
        {
            if(i!=v.size()-1)
                ans+=v[i]+" ";
            else
                ans+=v[i];
        }
        return ans;
    }
};