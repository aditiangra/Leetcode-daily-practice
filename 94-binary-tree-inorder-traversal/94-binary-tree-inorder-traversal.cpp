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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>inorder;
        helper(inorder,root);
        return inorder;
    }
    void helper(vector<int>& inorder,TreeNode* root)
    {
        if(root==NULL)return;
        helper(inorder,root->left);
        inorder.push_back(root->val);
        helper(inorder,root->right);
    }
};