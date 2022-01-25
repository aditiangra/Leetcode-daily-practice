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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>inorder1;
        helper(root1,inorder1);
      
        helper(root2,inorder1);
    
        sort(inorder1.begin(),inorder1.end());
        return inorder1;
    }
    void helper(TreeNode* root,vector<int>&inorder)
    {
        if(root==nullptr)return;
        helper(root->left,inorder);
        inorder.push_back(root->val);
        helper(root->right,inorder);
    }
};