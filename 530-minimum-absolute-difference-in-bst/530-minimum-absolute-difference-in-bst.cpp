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
    int getMinimumDifference(TreeNode* root) {
        if(root==nullptr)return 0;
        vector<int>inorder;
        solve(inorder,root);
       int diff=INT_MAX;
        for(int i=0;i<inorder.size();i++)
        {
            for(int j=i+1;j<inorder.size() ;j++)
            {
                if(diff>inorder[j]-inorder[i])
                {
                    diff=inorder[j]-inorder[i];
                }
            }
        }
        return diff;
    }
    void solve(vector<int>&inorder,TreeNode* root)
    {
        if(root==nullptr)return;
        solve(inorder,root->left);
        inorder.push_back(root->val);
        solve(inorder,root->right);
    }
};