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
    int findH(TreeNode* root)
    {
        if(root==nullptr)return 0;
        return 1+max(findH(root->left),findH(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(root==nullptr)return true;
        int lh=findH(root->left);
        int rh=findH(root->right);
        if(abs(lh-rh)<=1 and isBalanced(root->left) and isBalanced(root->right))return true;
        return false;
    }
};