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
    bool hasPathSum(TreeNode* root, int target) {
        if(root==nullptr)return false;
        if(root->val==target and root->left==nullptr and root->right==nullptr)return true;
        bool l=hasPathSum(root->left,target-root->val);
        bool r=hasPathSum(root->right,target-root->val);
        if(l || r)return true;
            return false;
    }
};