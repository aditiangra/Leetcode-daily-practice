class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<mat.size();i++)
            pq.push({accumulate(mat[i].begin(),mat[i].end(),0),i});
        vector<int>v(k);
        for(int i=0;i<k;i++)
        {
            if(pq.empty())break;
            v[i]=pq.top().second;
            pq.pop();
        }return v;
    }
};