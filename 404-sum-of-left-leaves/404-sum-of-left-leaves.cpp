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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        if(root==nullptr)return sum;
        solve(root,sum);
        return sum;
    }
    void solve(TreeNode* root,int &sum)
    {
        if(root==nullptr)return ;
        if(root->left!=nullptr and root->left->left==nullptr and root->left->right==nullptr)sum+=root->left->val;
        solve(root->left,sum);
        solve(root->right,sum);
    }
};