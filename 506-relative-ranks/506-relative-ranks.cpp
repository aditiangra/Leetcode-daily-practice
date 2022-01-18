class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
     priority_queue<pair<int,int>>q;
        for(int i=0;i<score.size();i++)
        {
            q.push({score[i],i});
        }
        int times=0;
        vector<string>result(score.size());
        while(q.empty()==false)
        {
            int idx=q.top().second;
            q.pop();
              if (times == 0)          result[idx] = "Gold Medal";
            else if (times == 1)     result[idx] = "Silver Medal";
            else if (times == 2)     result[idx] = "Bronze Medal";
            else                     result[idx] = to_string(times + 1);
            times++;
        }
        return result;
    }
};