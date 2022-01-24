class Solution {
public:
      bool isPowerTwo(long long n){
        return ((n - 1)&n) == 0;
    }
    int levelstart(long long n)
    {
        while(isPowerTwo(n)==false)
        {
            n++;
        }
        return n/2;
    }
    int getParent(int n)
    {
        if(isPowerTwo(n)==true)return n-1;
        else
        {
            int level=levelstart(n);
            int diff=(n-level)/2;
            return level-1-diff;
            
        }
    }
    vector<int> pathInZigZagTree(int label) {
        vector<int>result;
        result.push_back(label);
        while(label!=1)
        {
            int parent=getParent(label);
            result.push_back(parent);
            label=parent;
        }
        reverse(result.begin(),result.end());
        return result;
    }
};