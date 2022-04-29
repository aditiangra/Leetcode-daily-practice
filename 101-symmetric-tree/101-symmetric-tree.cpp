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
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr)return true;
        return solve(root->left,root->right);
    }
    bool solve(TreeNode* l,TreeNode* r)
    {
        if(l==NULL and r==NULL)return true;
        if(l==NULL or r==NULL)return false;
        if(l->val!=r->val)return false;
        bool lef=solve(l->left,r->right);
        bool rig=solve(l->right,r->left);
        if(lef and rig)return true;
        return false;
    }
};