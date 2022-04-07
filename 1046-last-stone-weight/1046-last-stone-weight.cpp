class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pr;
        for(int i=0;i<stones.size();i++)
        {
            pr.push(stones[i]);
        }
        while(true)
        {
            if(pr.size()==0)
            {
                return 0;
            }
            else if(pr.size()==1)
            {
                return pr.top();
            }
            else
            {
                int a=pr.top();
                pr.pop();
                int b=pr.top();
                pr.pop();
                if(a!=b)
                {
                    pr.push(abs(a-b));
                }
            }
        }
    }
};