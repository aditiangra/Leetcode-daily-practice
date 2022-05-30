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
    bool isValidBST(TreeNode* root) {
      if(root==NULL)return true;
    vector<int>inorder;
        helper(root,inorder);
        vector<int> ans=inorder;

        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size()-1;i++)
        {
            if(ans[i]==ans[i+1])return false;
        }
        return ans==inorder;
    }
    void helper(TreeNode* root,vector<int>& ans)
    {
        if(root==NULL)return;
        helper(root->left,ans);
        ans.push_back(root->val);
        helper(root->right,ans);
    }
};