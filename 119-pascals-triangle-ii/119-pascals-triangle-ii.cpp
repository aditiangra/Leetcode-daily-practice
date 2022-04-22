class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v(rowIndex+1);
        long temp=1;
       int up=rowIndex;
        int down=1;
        v[0]=v[rowIndex]=1;
        for(int i=1,up=rowIndex,down=1;i<rowIndex;i++,up--,down++)
        {
            temp=temp*up/down;
            v[i]=temp;
        }
        return v;
    }
};