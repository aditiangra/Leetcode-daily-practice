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
    TreeNode* increasingBST(TreeNode* root) {
        vector<int>inorder;
        helper(root,inorder);
        TreeNode* ans=new TreeNode(inorder[0]);
        TreeNode* res=ans;
        for(int i=1;i<inorder.size();i++)
        {
            TreeNode* dummy=new TreeNode(inorder[i]);
            res->right=dummy;
            res=res->right;
        }
        return ans;
    }
    void helper(TreeNode* root,vector<int>& ans)
    {
        if(root==NULL)return;
        helper(root->left,ans);
        ans.push_back(root->val);
        helper(root->right,ans);
    }
};