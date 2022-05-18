class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        //max heap to store numbers greater than k//
        priority_queue<pair<int,int>>pq;
        int res=INT_MIN;
        for (auto p:points)
        {
            while(pq.empty()==false and p[0]-pq.top().second>k)
            {
                pq.pop();
            } 
            if(pq.empty()==false)
            {
                res=max(res,pq.top().first+p[0]+p[1]);
            }
                
                pq.push({p[1]-p[0],p[0]});
            
        }
        return res;
    }
};