class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
     vector<int> ds;
        vector<vector<int>> ans;
        f(candidates.size()-1,target,candidates,ds,ans);
        return ans;
    }
    void f(int ind,int target,vector<int>&arr,vector<int>&ds, vector<vector<int>> &ans)
    {
        if(target==0)
        {
            ans.push_back(ds);
            return;
        }
        if(ind<0)return;
        if(arr[ind]<=target)
        {
            ds.push_back(arr[ind]);
            f(ind,target-arr[ind],arr,ds,ans);
            ds.pop_back();
        }
        f(ind-1,target,arr,ds,ans);
    }
};