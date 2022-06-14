/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>mpp;//hd----lvl-----nodes in vector//
        queue<pair<TreeNode*,pair<int,int>>>q;//---root,hd,lvl//
        vector<vector<int>> ans;
        if(root==NULL)return ans;
        q.push({root,{0,0}});
        while(q.empty()==false)
        {
            int size=q.size();
            auto temp=q.front();
            q.pop();
            TreeNode* frontnode=temp.first;
            int hd=temp.second.first;
            int lvl=temp.second.second;
            mpp[hd][lvl].insert(frontnode->val);
            if(frontnode->left!=NULL)q.push({frontnode->left,{hd-1,lvl+1}});
             if(frontnode->right!=NULL)q.push({frontnode->right,{hd+1,lvl+1}});
        }
        for(auto p:mpp)
        {
            vector<int>result;
            for(auto q:p.second)
            {
                result.insert(result.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(result);
        }
        return ans;
    }
};