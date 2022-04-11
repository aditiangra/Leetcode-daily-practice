class Solution {
public:
    string invert(string x){
        for(int i=0; i<x.size(); i++){
            if(x[i]=='0') x[i] ='1';
            else x[i] ='0';
        }            
        return x;
    }   
    char findKthBit(int n, int k) {
        string s=makeSeq(n);
        return s[k-1];
    }
    string makeSeq(int n)
    {
        if(n==0)return "0";
        string s=makeSeq(n-1);
        string ans="";
        string rev=invert(s);
        reverse(rev.begin(),rev.end());
        ans=s+"1"+rev;
        return ans;
    }
};