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
        find_inorder(inorder,root);
        TreeNode* ans=createTree(root,inorder);
        return ans;
    }
    TreeNode* createTree(TreeNode* root,vector<int>&inorder)
    {
        if(inorder.size()==0)return nullptr;
        TreeNode* res;
        TreeNode* ans=new TreeNode(inorder[0]);
        res=ans;
        for(int i=1;i<inorder.size();i++)
        {
            TreeNode* temp=new TreeNode(inorder[i]);
            ans->right=temp;
            ans=ans->right;
        }
        ans->right=nullptr;
        return res;
    }
    void find_inorder(vector<int>&inorder,TreeNode* root)
    {
        if(root==nullptr)return ;
        find_inorder(inorder,root->left);
        inorder.push_back(root->val);
        find_inorder(inorder,root->right);
    }
};