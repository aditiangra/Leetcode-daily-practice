class Solution {
public:
    string frequencySort(string s) {
        map<char,int>mpp;
        for(int i=0;i<s.size();i++)
        {
            mpp[s[i]]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto it:mpp)
        {
            pq.push({it.second,it.first});
        }
        string result="";
        while(pq.empty()==false)
        {
            auto it=pq.top();
            pq.pop();
            for(int i=0;i<it.first;i++)
            {
                result+=it.second;
            }
        }
        return result;
    }
};