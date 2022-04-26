class Solution {

public: 
    vector<vector<string>> ans;

bool safe(vector<string>&board,int row,int col,int n)
{
// { check upper diagonal 
//     lower diagonal 
//     check left row
    int drow=row;
    int dcol=col;
   while(dcol>=0)
   {
        if(board[drow][dcol]=='Q')
        {
            return false;
        }
       dcol--;
    }
     drow=row;
     dcol=col;
    while(drow>=0 && dcol>=0)
    {
        if(board[drow][dcol]=='Q')
        {
            return false;
        }
        drow--;
        dcol--;
        
    }
     drow=row;
     dcol=col;
     while(drow<n && dcol>=0)
    {
        if(board[drow][dcol]=='Q')
        {
            return false;
        }
        drow++;
        dcol--;
        
    }
    return true;
}
void solve(int col,vector<string>&board,int n)
{
    if(col==n)// if visited all col means no issue then push this board to ans
    {
        ans.push_back(board);
        return ;
    }
    for(int row=0;row<n;++row) // checking all row in a particular col
    {
        if(safe(board,row,col,n)==true)
        {    board[row][col]='Q';
             solve(col+1,board,n);
             board[row][col]='.';
        }
    }
}
vector<vector<string>> solveNQueens(int n) {
    vector<string>board(n);// board of size n*n
    
    string s(n,'.');
    for(int i=0;i<n;++i)
    {
        board[i]=s;
    }
    solve(0,board,n);
    return ans;
}
};