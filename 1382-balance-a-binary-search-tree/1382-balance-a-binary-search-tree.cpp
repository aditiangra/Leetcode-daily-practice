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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>inorder;
        helper(root,inorder);
        int start=0;
        int end=inorder.size()-1;
        TreeNode* ans=makeTree(inorder,start,end);
        return ans;
    }
    TreeNode* makeTree(vector<int>&inorder,int start,int end)
    {
        if(start>end)return nullptr;
        int mid=start+(end-start)/2;
        TreeNode* root =new TreeNode(inorder[mid]);
        root->left=makeTree(inorder,start,mid-1);
        root->right=makeTree(inorder,mid+1,end);
        return root;
    }
    void helper(TreeNode* root,vector<int>&inorder)
    {
        if(root==nullptr)return ;
        helper(root->left,inorder);
        inorder.push_back(root->val);
        helper(root->right,inorder);
    }
};