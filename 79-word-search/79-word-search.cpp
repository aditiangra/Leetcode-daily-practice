class Solution {
public:
    bool isValid(vector<vector<char>>& board,int i, int j,string &word,int pos)
    {
        if(i>=0 and j>=0 and i<board.size() and j<board[0].size() and board[i][j]==word[pos])
            return true;
        return false;
    }
    bool search(vector<vector<char>>& board,int i, int j,string &word,int pos)
    {
        if(pos==word.size()-1)
        {
            return true;
        }
        board[i][j]-=65;
        if(isValid(board,i-1,j,word,pos+1)==true)
        {
            if(search(board,i-1,j,word,pos+1)==true)
            {
                return true;
            }
        }
        if(isValid(board,i+1,j,word,pos+1)==true)
        {
            if(search(board,i+1,j,word,pos+1)==true)
            {
                return true;
            }
        }
        if(isValid(board,i,j-1,word,pos+1)==true)
        {
            if(search(board,i,j-1,word,pos+1)==true)
            {
                return true;
            }
        }
        if(isValid(board,i,j+1,word,pos+1)==true)
        {
            if(search(board,i,j+1,word,pos+1)==true)
            {
                return true;
            }
        }
        board[i][j]+=65;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
for(int i=0;i<board.size();i++)
{
    for(int j=0;j<board[0].size();j++)
    {
        if(board[i][j]==word[0])
        {
            if(search(board,i,j,word,0)==true)
            {
                return true;
            }
        }
    }
}
        return false;
    }
};