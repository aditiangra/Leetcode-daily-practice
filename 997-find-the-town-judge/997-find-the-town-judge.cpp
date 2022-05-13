class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
         vector<int> t(N+1,0);
        for(int i=0;i<trust.size();i++){
            t[trust[i][0]]--;
            t[trust[i][1]]++;
        }
        for(int i=1;i<t.size();i++){
            if(t[i]==N-1) return i;
        }
        return -1;
    }
};