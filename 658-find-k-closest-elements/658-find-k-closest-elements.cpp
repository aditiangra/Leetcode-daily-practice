class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>>q;
        vector<int>result;
        for(int i=0;i<arr.size();i++)
        {
            q.push({abs(arr[i]-x),arr[i]});
            if(q.size()>k)
            {
                q.pop();
            }
        }
        while(q.empty()==false)
        {
            result.push_back(q.top().second);
            q.pop();
        }
        sort(result.begin(),result.end());
        return result;
    }
};