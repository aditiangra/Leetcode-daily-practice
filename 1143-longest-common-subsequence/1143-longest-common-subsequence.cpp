//topic:lcs question1//
class Solution {
public:
    
    int longestCommonSubsequence(string text1, string text2) {
        //increasing everything by one//
        int n=text1.size();
        int m=text2.size();
         vector<vector<int>> dp(n+1,vector<int>(m+1,0));//dp array initiated by one//
    for(int i=0;i<=n;i++)dp[i][0]=0;
    for(int j=0;j<=m;j++)dp[0][j]=0;
        for(int ind1=1;ind1<=n;ind1++)
        {
            for(int ind2=1;ind2<=m;ind2++)
            {
                  if(text1[ind1-1]==text2[ind2-1])  dp[ind1][ind2]=1+dp[ind1-1][ind2-1];
                  else dp[ind1][ind2]=max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
            
            }
        }
    int len=dp[n][m];
        int i=n;
        int j=m;
        int index=len-1;
        string str="";
        for(int k=1;k<=len;k++)str+="$";
        while(i>0 and j>0)
        {
             if (text1[i - 1] == text2[j - 1]) {
             str[index] = text1[i - 1];
             index--;
             i--;
             j--;
         } 
            else if (text1[i - 1] > text2[j - 1]) {
               i--;
              }
            else j--;
        }
           cout << str;
        return len;
        
        
  }
};